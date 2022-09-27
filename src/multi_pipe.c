/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:17:34 by rhong             #+#    #+#             */
/*   Updated: 2022/09/27 17:37:20 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void				multi_pipe(int input_cnt, char **input, char **environ);
static t_pipe_data	*m_pipe_data_set(int input_cnt, char **input, \
char **environ);
static int			m_infile_open(char *infile_path);
static int			m_outfile_open(char *outfile_path);
void				free_all(t_pipe_data *p_data);

void	multi_pipe(int input_cnt, char **input, char **environ)
{
	t_pipe_data	*p_data;

	p_data = m_pipe_data_set(input_cnt, input, environ);
	m_pipe(p_data);
	free_all(p_data);
}

static t_pipe_data	*m_pipe_data_set(int input_cnt, char **input, \
char **environ)
{
	t_pipe_data	*p_data;

	p_data = (t_pipe_data *)malloc(sizeof(t_pipe_data));
	if (p_data == 0)
	{
		perror("MALLOC P_DATA ERROR: ");
		exit(1);
	}
	p_data->infile = m_infile_open(input[1]);
	p_data->outfile = m_outfile_open(input[input_cnt - 1]);
	p_data->cmd_cnt = 2;
	p_data->cmd = &(input[2]);
	p_data->environ = environ;
	return (p_data);
}

static int	m_infile_open(char *infile_path)
{
	int	fd;

	fd = open(infile_path, O_RDONLY, 0644);
	if (fd == 0)
	{
		perror("m_infile_open error: ");
		exit(1);
	}
	return (fd);
}

static int	m_outfile_open(char *outfile_path)
{
	int	fd;

	fd = open(outfile_path, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == 0)
	{
		perror("m_outfile_open error: ");
		exit(1);
	}
	return (fd);
}

void	free_all(t_pipe_data *p_data)
{
	free(p_data);
}
