#include "pipex.h"

void	pipex(int ac, char **av, char **env);

int	main(int ac, char **av, char **env)
{
	pipex(ac, av, env);
	return (0);
}

void	pipex(int ac, char **av, char **env)
{
	t_p_data	*p_data;
	int			fork_cnt;
	int			pipe_fd[2];
	pid_t		*pids;

	if (input_err(ac))
		return ;
	p_data = set_p_data(ac, av, env);
	fork_cnt = 0;
	pids = (pid_t *)malloc(sizeof(pid_t) * p_data->cmd_cnt);
	while (fork_cnt < p_data->cmd_cnt)
	{
		pids[fork_cnt] = fork();
		if (pids[fork_cnt] == 0)
			child(p_data);
		fork_cnt++;
	}
	close_pipes(pipe_fd);
	fork_cnt = 0;
	while (fork_cnt < p_data->cmd_cnt)
	{
		waitpid(pids[fork_cnt], 0, 0);
		fork_cnt++;
	}
}
