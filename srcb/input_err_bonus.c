/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_err_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:56:26 by rhong             #+#    #+#             */
/*   Updated: 2022/09/30 15:56:28 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	input_err(int ac, char **av)
{
	if (ac >= 6 && ft_strcmp("here_doc", av[1]) == 0)
		return (0);
	else if (ac >= 5)
		return (1);
	else
	{
		perror("wrong argument err");
		return (2);
	}
	return (0);
}
