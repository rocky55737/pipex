/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:07:05 by rhong             #+#    #+#             */
/*   Updated: 2022/09/27 14:15:32 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipex_bonus(int input_cnt, char **input, char **environ);

int	main(int argc, char **argv, char **environ)
{
	pipex_bonus(argc, argv, environ);
	return (0);
}

void	pipex_bonus(int input_cnt, char **input, char **environ)
{
	if (h_input_err_check(input_cnt, input))
		here_doc(input_cnt, input, environ);
	else if (m_input_err_check(input_cnt, input))
		multi_pipe(input_cnt, input, environ);
	else
		perror("INPUT ERROR");
	return ;
}