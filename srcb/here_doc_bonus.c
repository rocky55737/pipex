/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:56:18 by rhong             #+#    #+#             */
/*   Updated: 2022/10/02 16:21:33 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (fork_cnt != p_data->cmd_cnt - 1)
		{
			close(p_data->pipes_fd[fork_cnt % 2][1]);
			if (fork_cnt != 0)
				close(p_data->pipes_fd[(fork_cnt + 1) % 2][0]);
		}
		fork_cnt++;
	}
	wait_all(p_data->pids, p_data->cmd_cnt);
	unlink("/tmp/.here_doc.txt");
}
