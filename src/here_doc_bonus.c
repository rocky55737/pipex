/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:40:45 by rhong             #+#    #+#             */
/*   Updated: 2022/09/26 17:50:13 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void				here_doc(int input_cnt, char **input, char **environ);
static t_pipe_data	*h_pipe_data_set(int input_cnt, char **input, char **environ);
static int			h_infile_create(void);
static int			h_outfile_open(char *outfile_path);
static void			h_delet_infile(int infile_fd);

void	here_doc(int input_cnt, char **input, char **environ)
{
	t_pipe_data	*p_data;

	p_data = (t_pipe_data *)malloc(sizeof(t_pipe_data));
	if (p_data == 0)
	{
		perror("MALLOC P_DATA ERROR: ");
		exit(1);
	}
	p_data = h_pipe_data_set(input_cnt, input, environ);
	m_pipe(p_data);
	h_delet_infile(p_data->infile);
	free_all(p_data);
}

static t_pipe_data	*h_pipe_data_set(int input_cnt, char **input, char **environ)
{
	t_pipe_data	*p_data;

	p_data = (t_pipe_data *)malloc(sizeof(t_pipe_data));
	if (p_data == 0)
	{
		perror("MALLOC P_DATA ERROR: ");
		exit(1);
	}
	p_data->infile = h_infile_create();
	p_data->outfile = h_outfile_open(input[input_cnt - 1]);
	p_data->cmd_cnt = input_cnt - 4;
	p_data->cmd = &(input[3]);
	p_data->environ = environ;
	return (p_data);
}

static int	h_infile_create(void)
{
	int	fd;

	fd = open("/tmp/.heredoc", O_CREAT | O_RDWR);
	if (fd == 0)
	{
		perror("h_infile_create error: ");
		exit(1);
	}
	return (fd);
}

static int	h_outfile_open(char *outfile_path)
{
	int	fd;

	fd = open(outfile_path, O_CREAT | O_APPEND | O_WRONLY);
	if (fd == 0)
	{
		perror("h_outfile_open error: ");
		exit(1);
	}
	return (fd);
}

static void	h_delet_infile(int infile_fd)
{
	if (close(infile_fd) == -1)
	{
		perror("h_delet_infile close error: ");
		exit(1);
	}
	if (unlink("/tmp/.heredoc") == -1)
	{
		perror("h_delet_infile ulink error: ");
		exit(1);
	}
}
