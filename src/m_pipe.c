#include "pipex_bonus.h"

void	m_pipe(t_pipe_data *p_data);

void	m_pipe(t_pipe_data *p_data);
{
	int		pipe_cnt;
	int		pipe[2][2];
	pid_t	pid*;

	pipe_cnt = 0;
	while (pipe_cnt < p_data->cmd_cnt)
	{
		pipe_open(pipe[pipe_cnt % 2]);
		pid[pipe_cnt] = fork();
		child(pid, pipe_cnt, p_data);
		
	}
}


