/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:42:03 by rhong             #+#    #+#             */
/*   Updated: 2022/09/21 17:06:35 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child(t_chlid_data	c_data);

void	child(t_chlid_data	c_data)
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
