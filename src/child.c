/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:42:03 by rhong             #+#    #+#             */
/*   Updated: 2022/09/21 19:45:33 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void			child(t_child_data	c_data);
t_child_data	child_data_set(int *pids, int pipe_cnt, t_pipe_data *p_data, \
int pipes[2][2]);

void	child(t_child_data	c_data)
{
	char	**command;
	char	*cmd_path;

	if (c_data.pid != 0)
		return ;
	command = ft_split(c_data.p_d->cmd[c_data.pipe_cnt], ' ');
	cmd_path = cmd_path_find(command[1]);
	io_dup(c_data.fd_in_out);
	fd_arr_close(c_data.fd_to_close);
	execve(cmd_path, command, 0);
}

t_child_data	child_data_set(int *pids, int pipe_cnt, t_pipe_data *p_data, \
int pipes[2][2])
{
	t_child_data	c_data;

	c_data.pid = pids[pipe_cnt];
	c_data.pipe_cnt = pipe_cnt;
	c_data.p_d = p_data;
	c_data.fd_to_close[1] = 0;
	c_data.fd_in_out[0] = pipes[(pipe_cnt + 1) % 2][0];
	c_data.fd_in_out[1] = pipes[pipe_cnt][1];
	c_data.fd_to_close[0] = pipes[(pipe_cnt + 1) % 2][1];
	c_data.fd_to_close[0] = pipes[pipe_cnt][0];
	if (pipe_cnt == 0)
		c_data.fd_in_out[0] = p_data->infile;
	else if (pipe_cnt == p_data->cmd_cnt - 1)
		c_data.fd_in_out[1] = p_data->outfile;
	return (c_data);
}
