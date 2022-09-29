#include "pipex_bonus.h"

void	here_doc(int ac, char **av, char **env)
{
	t_p_data	*p_data;
	int			fork_cnt;

	p_data = h_set_p_data(ac, av, env);
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
    unlink("/tmp/.here_doc.txt");
}