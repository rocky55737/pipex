/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:58:42 by rhong             #+#    #+#             */
/*   Updated: 2022/09/30 15:58:46 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char		**set_cmd(char *cmd_to_set);
static int	has_two_quotes(char *str);

char	**set_cmd(char *cmd_to_set)
{
	char	**cmd;

	if (has_two_quotes(cmd_to_set))
		cmd = rm_quotes(cmd_to_set);
	else
		cmd = ft_split(cmd_to_set, ' ');
	return (cmd);
}

static int	has_two_quotes(char *str)
{
	char	*tmp;

	tmp = ft_strchr(str, '\'');
	if (tmp)
	{
		tmp = ft_strchr(tmp + 1, '\'');
		if (tmp)
			return (1);
	}
	tmp = ft_strchr(str, '\"');
	if (tmp)
	{
		tmp = ft_strchr(tmp + 1, '\"');
		if (tmp)
			return (1);
	}
	return (0);
}
