/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_err_check_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:27:35 by rhong             #+#    #+#             */
/*   Updated: 2022/09/17 16:36:37 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int			h_input_err_check(int input_cnt, char **input);
int			m_input_err_check(int input_cnt, char **input);

int	h_input_err_check(int input_cnt, char **input)
{
	if (input_cnt >= 6 && ft_strcmp(input[1], "here_doc") == 0)
		return (1);
	return (0);
}

int	m_input_err_check(int input_cnt, char **input)
{
	if (input_cnt >= 5 && access(input[1], R_OK) == 0)
		return (1);
	return (0);
}
