#include "pipex_bonus.h"

void		m_pipe(t_pipe_data *p_data);
static void	pipe_open(int pipe_fd[2]);
static void	pipe_close(int pipe_fd[2]);

void	m_pipe(t_pipe_data *p_data);
{
	int		pipe_cnt;
	int		pipes[2][2];
	pid_t	*pids;

	pipe_cnt = 0;
	pids = (pid_t *)malloc(sizeof(pid_t) * p_data->cmd_cnt);
	while (pipe_cnt < p_data->cmd_cnt)
	{
		pipe_open(pipes[pipe_cnt % 2]);
		pids[pipe_cnt] = fork();
		if (pid[pipe_cnt] < 0)
		{
			perror("fork error: ");
			exit(1);
		}
		//infile fd outfile fd 판단후 넣기
		child(pids, in, out, p_data);
		pipe_close(pipe[pipe_cnt % 2]);
	}
	waitpid(pids);
}

void	pipe_open(int pipe_fd[2])
{
	if (pipe(pipe_fd) < 0)
	{
		perror("pipe open error: ");
		exit(1);
	}
}

void	pipe_close(int pipe_fd[2])
{
	if (close(pipe_fd[0]) < -1)
	{
		perror("pipe close error: ");
		exit(-1);
	}
	if (close(pipe_fd[1]) < -1)
	{
		perror("pipe close error: ");
		exit(-1);
	}
}
