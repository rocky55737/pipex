/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:37:56 by rhong             #+#    #+#             */
/*   Updated: 2022/10/02 17:51:40 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char		**rm_quotes(char *str);
static int	find_quotes_from_start(char *str);
static int	find_quotes_from_last(char *str, char which_q);

char	**rm_quotes(char *str)
{
	int		first_q;
	int		last_q;
	char	**ret;

	first_q = find_quotes_from_start(str);
	last_q = find_quotes_from_last(str, str[first_q]);
	ret = (char **)malloc(sizeof(char *) * 4);
	if (ret == 0)
	{
		perror("rm_quotes malloc error:");
		exit(1);
	}
	ret[0] = ft_substr(str, 0, first_q - 1);
	ret[1] = ft_substr(str, first_q + 1, last_q - first_q - 1);
	if (ft_strlen(str) - last_q != 1)
		ret[2] = ft_substr(str, last_q + 2, ft_strlen(str) - last_q);
	else
		ret[2] = 0;
	ret[3] = 0;
	return (ret);
}

static int	find_quotes_from_start(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\'' && str[index] != '\"')
		index++;
	return (index);
}

static int	find_quotes_from_last(char *str, char which_q)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	while (str[index - 1] != which_q)
		index--;
	return (index - 1);
}
