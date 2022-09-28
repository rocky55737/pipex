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

	if (input_err(ac))
		return ;
	p_data = set_p_data(ac, av, env);
	pipe(p_data->pipes_fd);
	fork_cnt = 0;
	while (fork_cnt < p_data->cmd_cnt)
	{
		p_data->pids[fork_cnt] = fork();
		if (p_data->pids[fork_cnt] == 0)
			child(p_data, fork_cnt);
		fork_cnt++;
	}
	close_pipes(p_data->pipes_fd);
	fork_cnt = 0;
	while (fork_cnt < p_data->cmd_cnt)
	{
		waitpid(pids[fork_cnt], 0, 0);
		fork_cnt++;
	}
}

