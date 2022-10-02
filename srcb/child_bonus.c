/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:55:35 by rhong             #+#    #+#             */
/*   Updated: 2022/10/03 05:52:43 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void		child(t_p_data *p_data, int fork_cnt);
static void	dups(t_p_data *p_data, int fork_cnt);

void	child(t_p_data *p_data, int fork_cnt)
{
	char	**cmd;
	char	*cmd_path;

	cmd = set_cmd(p_data->cmds[fork_cnt]);
	cmd_path = find_cmd_path(p_data, cmd[0]);
	dups(p_data, fork_cnt);
	if (fork_cnt < p_data->cmd_cnt - 1)
		close_pipes(p_data->pipes_fd[fork_cnt]);
	if (fork_cnt > 0)
		close_pipes(p_data->pipes_fd[(fork_cnt + 1) % 2]);
	if (!p_data->env)
		execve(cmd_path, cmd, 0);
	execve(cmd_path, cmd, p_data->env);
}

static void	dups(t_p_data *p_data, int fork_cnt)
{
	if (fork_cnt == 0)
	{
		if (p_data->in_out_fd[0] == -1)
		{
			perror("pipex: input");
			exit(1);
		}
		dup2(p_data->in_out_fd[0], 0);
		dup2(p_data->pipes_fd[0][1], 1);
	}
	else if (fork_cnt == p_data->cmd_cnt - 1)
	{
		if (p_data->in_out_fd[1] == -1)
		{
			perror("pipex: output");
			exit(1);
		}
		dup2(p_data->pipes_fd[(fork_cnt + 1) % 2][0], 0);
		dup2(p_data->in_out_fd[1], 1);
	}
	else
	{
		dup2(p_data->pipes_fd[(fork_cnt + 1) % 2][0], 0);
		dup2(p_data->pipes_fd[fork_cnt % 2][1], 1);
	}
}
