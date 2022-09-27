/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:07:05 by rhong             #+#    #+#             */
/*   Updated: 2022/09/27 14:18:45 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int input_cnt, char **input, char **environ);

int	main(int argc, char **argv, char **environ)
{
	pipex(argc, argv, environ);
	return (0);
}

void	pipex(int input_cnt, char **input, char **environ)
{
	if (m_input_err_check(input_cnt, input))
		multi_pipe(input_cnt, input, environ);
	else
		perror("INPUT ERROR");
	return ;
}
