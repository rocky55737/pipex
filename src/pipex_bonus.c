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
#include "../get_next_line/get_next_line_bonus.h"
#include "../libft/libft.h"

void	here_doc(char *limiter, int *infile_fd);
void	pipex_bonus(int input_cnt, char **input);
void	here_doc(int input_cnt, char **input);
void	multi_pipe(int input_cnt, char **input);
t_pipe_data	*h_pipe_data_set(int input_cnt, char **input);

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

void	here_doc(int input_cnt, char **input)
{
	t_pipe_data	*p_data;

	p_data = h_pipe_data_set(input_cnt, input);
	m_pipe(p_data);
	h_delet_infile(p_data->infile);
	free_all(p_data);
}

void	h_pipe_data_set(int input_cnt, char **input)
{
	t_pipe_data	*p_data;

	p_data = (t_pipe_data *)malloc(sizeof(t_pipe_data));
	if (p_data == 0)
		{
			perror("MALLOC ERROR");
			exit();
		}
	p_data->infile = h_infile_create();
	p_data->outfile = h_outfile_open();
	pipe_open();
	return (p_data);
}
