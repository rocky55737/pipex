#include "./get_next_line/get_next_line_bonus.h"
#include "./libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int ac, char **av, char **env)
{
    int in_out_fd[2];
    int pipe_fd[2];
    pid_t pids[2];
    int fork_cnt;
    char **cmds;
    char *cmd_path;
    char **cmd;
    char **all_paths;
    int all_paths_cnt;
    int env_cnt;

    cmds = &(av[2]);
    
    in_out_fd[0] = open(av[1], O_RDONLY, 0644);
    in_out_fd[1] = open(av[4], O_TRUNC | O_RDWR | O_CREAT, 0666);
    pipe(pipe_fd);

    fork_cnt = 0;
    while (fork_cnt < 2)
    {
        pids[fork_cnt] = fork();
        if (pids[fork_cnt] == 0)
        {
            cmd = ft_split(cmds[fork_cnt], ' ');
            env_cnt = 0;

            while (ft_strncmp("PATH=", env[env_cnt], 5) != 0)
                env_cnt++;
            
            all_paths = 0;
            all_paths = ft_split(&(env[env_cnt][5]), ':');

            all_paths_cnt = 0;
            while (all_paths[all_paths_cnt])
            {
                all_paths[all_paths_cnt] = ft_strjoin(all_paths[all_paths_cnt], "/");
                all_paths_cnt++;
            }

            all_paths_cnt = 0;
            while (all_paths[all_paths_cnt])
            {
                all_paths[all_paths_cnt] = ft_strjoin(all_paths[all_paths_cnt], cmd[0]);
                all_paths_cnt++;
            }

            all_paths_cnt = 0;
            while (access(all_paths[all_paths_cnt], X_OK) != 0)
                all_paths_cnt++;

            cmd_path = all_paths[all_paths_cnt];

            if (fork_cnt == 0)
            {
                dup2(in_out_fd[0], 0);
                dup2(pipe_fd[1], 1);
                close(pipe_fd[0]);
                close(pipe_fd[1]);
            }
            else
            {
                dup2(pipe_fd[0], 0);
                dup2(in_out_fd[1], 1);
                close(pipe_fd[0]);
                close(pipe_fd[1]);
            }
            execve(cmd_path, cmd, env);
        }
        fork_cnt++;
    }
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    for (int a=0; a<2; a++)
    {
        wait(0);
    }
    return (0);
}