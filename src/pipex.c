/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:04:23 by rhong             #+#    #+#             */
/*   Updated: 2022/10/02 16:38:34 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int ac, char **av, char **env);
void	close_pipes(int fd_arr[2]);

void	pipex(int ac, char **av, char **env)
{
	t_p_data	*p_data;
	int			fork_cnt;

	if (input_err(ac))
		exit(1);
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
