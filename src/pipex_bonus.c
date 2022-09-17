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

void		here_doc(char *limiter, int *infile_fd);
t_pipe_data	*here_doc_input(int ac, char **av);
t_pipe_data	*multi_pipe_input(int ac, char **av);
void		pipex(t_pipe_data *p_data);
void		free_pipe(t_pipe_data *p_data);

int	main(int argc, char **argv)
{
	t_pipe_data	*p_data;
	int			input_error_check;
	int			infile_fd;
	int			outfile_fd;

	input_error_check = input_err_check(argc, argv);
	if (input_error_check == 0)
		p_data = multi_pipe_input(argc, argv);
	else if (input_error_check == 1)
	{
		here_doc(argv[2], &infile_fd);
		p_data = here_doc_input(argc, argv);
	}
	else
	{
		perror("Input Error");
		return (0);
	}
	pipex(p_data);
	free_pipe(p_data);
	return (0);
}

void	here_doc(char *limiter, int *infile_fd)
{
	char	*buff;

	*infile_fd = open("/tmp/here_doc", O_CREAT | O_RDWR);
	buff = &(get_next_line(0)[0]);
	while (ft_strcmp(buff, limiter) != 0)
	{
		write(*infile_fd, buff, ft_strlen(buff));
		buff = &(get_next_line(0)[0]);
	}
}

t_pipe_data	*here_doc_input(int ac, char **av)
{
	t_pipe_data	*p_data;

	p_data = (t_pipe_data *)malloc(sizeof(t_pipe_data));
	p_data->infile = ft_strdup("/tmp/here_doc");
	p_data->cmd = &(av[3]);
	p_data->outfile = ft_strdup(av[ac - 1]);
	p_data->cmd_cnt = ac - 4;
	return (p_data);
}

t_pipe_data	*multi_pipe_input(int ac, char **av)
{
	t_pipe_data	*p_data;

	p_data = (t_pipe_data *)malloc(sizeof(t_pipe_data));
	p_data->infile = ft_strdup(av[1]);
	p_data->cmd = &(av[2]);
	p_data->outfile = ft_strdup(av[ac - 1]);
	p_data->cmd_cnt = ac - 3;
	return (p_data);
}
