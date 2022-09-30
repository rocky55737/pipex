/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_path_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:55:59 by rhong             #+#    #+#             */
/*   Updated: 2022/09/30 15:56:01 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*find_cmd_path(t_p_data *p_data, char *cmd)
{
	int		cnt;
	char	**all_paths;

	if (access(cmd, X_OK) != 0)
		return (cmd);
	cnt = 0;
	while (ft_strncmp("PATH=", p_data->env[cnt], 5) != 0)
		cnt++;
	all_paths = ft_split(&(p_data->env[cnt][5]), ':');
	cnt = 0;
	while (all_paths[cnt])
	{
		all_paths[cnt] = ft_strjoin(all_paths[cnt], "/");
		cnt++;
	}
	cnt = 0;
	while (all_paths[cnt])
	{
		all_paths[cnt] = ft_strjoin(all_paths[cnt], cmd);
		cnt++;
	}
	cnt = 0;
	while (access(all_paths[cnt], X_OK) != 0)
		cnt++;
	return (all_paths[cnt]);
}
