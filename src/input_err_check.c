/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_err_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:27:35 by rhong             #+#    #+#             */
/*   Updated: 2022/09/27 14:29:04 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int			m_input_err_check(int input_cnt, char **input);

int	m_input_err_check(int input_cnt, char **input)
{
	if (input_cnt == 5 && access(input[1], R_OK) == 0)
		return (1);
	return (0);
}
