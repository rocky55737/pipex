#include "pipex.h"

void	pipex(int ac, char **av, char **env);
void	close_pipes(int fd_arr[2]);

int	main(int ac, char **av, char **env)
{
	pipex(ac, av, env);
	return (0);
}

void	pipex(int ac, char **av, char **env)
{
	t_p_data	*p_data;
	int			fork_cnt;

	if (input_err(ac))
		return ;
	p_data = set_p_data(ac, av, env);
	fork_cnt = 0;
	while (fork_cnt < p_data->cmd_cnt)
	{
		if (fork_cnt < p_data->cmd_cnt - 1)
			pipe(p_data->pipes_fd[fork_cnt % 2]);
		p_data->pids[fork_cnt] = fork();
		if (p_data->pids[fork_cnt] == 0)
			child(p_data, fork_cnt);
		if (fork_cnt < p_data->cmd_cnt - 1)
			close_pipes(p_data->pipes_fd[fork_cnt % 2]);
		fork_cnt++;
	}
	fork_cnt = 0;
	while (fork_cnt < p_data->cmd_cnt)
	{
		waitpid(p_data->pids[fork_cnt], 0, 0);
		fork_cnt++;
	}
}

void	close_pipes(int fd_arr[2])
{
	if (fd_arr[0] != 0)
		close(fd_arr[0]);
	fd_arr[0] = 0;
	if (fd_arr[1] != 0)
		close(fd_arr[1]);
	fd_arr[1] = 0;
}