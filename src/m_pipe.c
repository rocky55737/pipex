/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_pipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:42:44 by rhong             #+#    #+#             */
/*   Updated: 2022/09/21 19:03:40 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void		m_pipe(t_pipe_data *p_data);
static void	pipe_open(int pipe_fd[2]);
void		fd_arr_close(int fd_arr[2]);
static void	wait_pids(pid_t *pids, int cnt);

void	m_pipe(t_pipe_data *p_data)
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
		if (pids[pipe_cnt] < 0)
		{
			perror("fork error: ");
			exit(1);
		}
		child(child_data_set(pids, pipe_cnt, p_data, pipes));
		fd_arr_close(pipes[pipe_cnt % 2]);
		pipe_cnt++;
	}
	wait_pids(pids, p_data->cmd_cnt);
}

void	pipe_open(int pipe_fd[2])
{
	if (pipe(pipe_fd) < 0)
	{
		perror("pipe open error: ");
		exit(1);
	}
}

void	fd_arr_close(int fd_arr[2])
{
	if (fd_arr[0] != 0)
	{
		if (close(fd_arr[0]) < -1)
		{
			perror("pipe close error: ");
			exit(-1);
		}
	}
	if (fd_arr[1] != 0)
	{
		if (close(fd_arr[1]) < -1)
		{
			perror("pipe close error: ");
			exit(-1);
		}
	}
}

static void	wait_pids(pid_t *pids, int cnt)
{
	int	pid_cnt;

	pid_cnt = 0;
	while (pid_cnt < cnt)
	{
		waitpid(pids[pid_cnt], 0, 0);
		pid_cnt++;
	}
}
