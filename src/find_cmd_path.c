/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:36:52 by rhong             #+#    #+#             */
/*   Updated: 2022/10/02 23:51:08 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	command_not_found(char *cmd);
char		*find_cmd_path(t_p_data *p_data, char *cmd);

char	*find_cmd_path(t_p_data *p_data, char *cmd)
{
	int		cnt;
	char	**all_paths;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	cnt = 0;
	while (ft_strncmp("PATH=", p_data->env[cnt], 5) != 0)
		cnt++;
	all_paths = ft_split(&(p_data->env[cnt][5]), ':');
	cnt = 0;
	while (all_paths[cnt])
	{
		all_paths[cnt] = ft_strjoin(ft_strjoin(all_paths[cnt], "/"), cmd);
		cnt++;
	}
	cnt = 0;
	while (all_paths[cnt] && access(all_paths[cnt], X_OK) != 0)
		cnt++;
	if (all_paths[cnt] == 0)
		command_not_found(cmd);
	return (all_paths[cnt]);
}

static void	command_not_found(char *cmd)
{
	char	*buff;

	buff = ft_strdup("pipex: ");
	buff = ft_strjoin(ft_strjoin(buff, cmd), ": command not found");
	write(2, buff, ft_strlen(buff));
	exit(127);
}
