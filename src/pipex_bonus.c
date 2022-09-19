/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:07:05 by rhong             #+#    #+#             */
/*   Updated: 2022/09/17 21:34:08 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipex_bonus(int input_cnt, char **input);

int	main(int argc, char **argv)
{
	pipex_bonus(argc, argv);
	return (0);
}

void	pipex_bonus(int input_cnt, char **input)
{
	if (h_input_err_check(input_cnt, input))
		here_doc(input_cnt, input);
	else if (m_input_err_check(input_cnt, input))
		multi_pipe(input_cnt, input);
	else
		perror("INPUT ERROR");
	return (0);
}
