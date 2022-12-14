/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_p_data_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:58:52 by rhong             #+#    #+#             */
/*   Updated: 2022/10/02 18:32:51 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_p_data	*set_p_data(int ac, char **av, char **env);
static int	infile_open(char *infile_path);
static int	outfile_open(char *outfile_path);

t_p_data	*set_p_data(int ac, char **av, char **env)
{
	t_p_data	*p_data;

	p_data = (t_p_data *)malloc(sizeof(t_p_data));
	if (p_data == 0)
	{
		perror("P_DATA ERR: ");
		exit(1);
	}
	p_data->in_out_fd[0] = infile_open(av[1]);
	p_data->in_out_fd[1] = outfile_open(av[ac - 1]);
	p_data->cmds = &(av[2]);
	p_data->cmd_cnt = ac - 3;
	p_data->env = env;
	p_data->pids = (pid_t *)malloc(sizeof(pid_t) * p_data->cmd_cnt);
	if (p_data->pids == 0)
	{
		perror("SET P_DATA PIDS MALLOC ERR:");
		exit(1);
	}
	return (p_data);
}

static int	infile_open(char *infile_path)
{
	int	fd;

	fd = open(infile_path, O_RDONLY, 0644);
	return (fd);
}

static int	outfile_open(char *outfile_path)
{
	int	fd;

	fd = open(outfile_path, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	return (fd);
}
