/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:38:07 by rhong             #+#    #+#             */
/*   Updated: 2022/09/30 14:38:39 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
