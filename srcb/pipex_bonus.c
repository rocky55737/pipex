/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:56:52 by rhong             #+#    #+#             */
/*   Updated: 2022/09/30 16:30:39 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipex_bonus(int ac, char **av, char **env);
void	multi_pipe(int ac, char **av, char **env);
void	close_pipes(int fd_arr[2]);
void	clean_pipes(int pipe_fd[2][2]);

void	pipex_bonus(int ac, char **av, char **env)
{
	int	flag;

	flag = input_err(ac, av);
	if (flag == 0)
		here_doc(ac, av, env);
	else if (flag == 1)
		multi_pipe(ac, av, env);
	else
		return ;
}

void	multi_pipe(int ac, char **av, char **env)
{
	t_p_data	*p_data;
	int			fork_cnt;

	p_data = set_p_data(ac, av, env);
	clean_pipes(p_data->pipes_fd);
	fork_cnt = 0;
	while (fork_cnt < p_data->cmd_cnt)
	{
		if (fork_cnt < p_data->cmd_cnt - 1)
			close_pipes(p_data->pipes_fd[fork_cnt % 2]);
		if (fork_cnt < p_data->cmd_cnt - 1)
			pipe(p_data->pipes_fd[fork_cnt % 2]);
		p_data->pids[fork_cnt] = fork();
		if (p_data->pids[fork_cnt] == 0)
			child(p_data, fork_cnt);
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

void	clean_pipes(int pipe_fd[2][2])
{
	int	cnt;
	int	cntt;

	cnt = 0;
	while (cnt < 2)
	{
		cntt = 0;
		while (cntt < 2)
		{
			pipe_fd[cnt][cntt] = 0;
		}
	}
}
