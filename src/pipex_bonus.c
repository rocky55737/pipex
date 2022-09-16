/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:07:05 by rhong             #+#    #+#             */
/*   Updated: 2022/09/16 18:48:58 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "../get_next_line/get_next_line_bonus.h"
#include "../libft/libft.h"

int			input_err_check(char **input);
void		here_doc(char *limiter);
t_pipe_data	here_doc_input(int ac, char **av);
t_pipe_data	multi_pipe_input(int ac, char **av);
void		pipex(t_pipe_data p_data);
int			h_input_err_check(char **input);
int			m_input_err_check(char **input);

int	main(int argc, char **argv)
{
	t_pipe_data	p_data;
	int			input_error_check;

	input_error_check = input_err_check(argv);
	if (input_err_check(argv) == 0)
		p_data = multi_pipe_input(argc, argv);
	else if (input_error_check == 1)
	{
		here_doc(argv[2]);
		p_data = here_doc_input(argc, argv);
	}
	else
	{
		//perror()
		return (0);
	}
	pipex(p_data);
}

int	input_err_check(char **input)
{
	int	input_error;

	if (ft_strcmp(input[1], "here_doc") == 0)
	{
		input_error = h_input_err_check(input);
		if (input_error == -1)
			return (-1);
		else
			return (1);
	}
	else
	{
		input_error = m_input_err_check(input);
		if (input_error == -1)
			return (-1);
		else
			return (0);
	}	
}
