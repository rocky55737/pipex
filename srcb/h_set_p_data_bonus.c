/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_set_p_data_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:56:09 by rhong             #+#    #+#             */
/*   Updated: 2022/10/03 05:51:58 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_p_data	*h_set_p_data(int ac, char **av, char **env);
static int	h_infile_open(char *infile_path, char *limiter);
static int	h_outfile_open(char *outfile_path);

t_p_data	*h_set_p_data(int ac, char **av, char **env)
{
	t_p_data	*p_data;

	p_data = (t_p_data *)malloc(sizeof(t_p_data));
	if (p_data == 0)
	{
		perror("P_DATA ERR: ");
		exit(1);
	}
	p_data->in_out_fd[0] = h_infile_open("here_doc.txt", av[2]);
	p_data->in_out_fd[1] = h_outfile_open(av[ac - 1]);
	p_data->cmds = &(av[3]);
	p_data->cmd_cnt = ac - 4;
	p_data->env = env;
	p_data->pids = (pid_t *)malloc(sizeof(pid_t) * p_data->cmd_cnt);
	if (p_data->pids == 0)
	{
		perror("SET P_DATA PIDS MALLOC ERR:");
		exit(1);
	}
	return (p_data);
}

static int	h_infile_open(char *infile_path, char *limiter)
{
	int		fd;
	char	*buffer;
	char	*n_lim;

	fd = open(infile_path, O_CREAT | O_RDWR, 0644);
	n_lim = ft_strjoin(ft_strdup(limiter), ft_strdup("\n"));
	buffer = get_next_line(0);
	while (ft_strcmp(n_lim, buffer) != 0)
	{
		write(fd, buffer, ft_strlen(buffer));
		free(buffer);
		buffer = get_next_line(0);
	}
	free(buffer);
	return (fd);
}

static int	h_outfile_open(char *outfile_path)
{
	int	fd;

	fd = open(outfile_path, O_APPEND | O_WRONLY | O_CREAT, 0644);
	return (fd);
}
