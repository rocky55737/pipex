/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:42:03 by rhong             #+#    #+#             */
/*   Updated: 2022/09/27 17:54:56 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void			child(t_child_data	c_data);
t_child_data	child_data_set(int *pids, int pipe_cnt, t_pipe_data *p_data, \
int pipes[2][2]);
static char		*cmd_path_find(char *cmd, char **environ);
static void		io_dup(int *in_out_fd);

void	child(t_child_data	c_data)
{
	char	**command;
	char	*cmd_path;

	if (c_data.pid != 0)
		return ;
	command = ft_split(c_data.p_d->cmd[c_data.pipe_cnt], ' ');
	cmd_path = cmd_path_find(command[0], c_data.p_d->environ);
	io_dup(c_data.fd_in_out);
	fd_arr_close(c_data.fd_to_close);
	if (execve(cmd_path, command, c_data.p_d->environ) == -1)
	{
		perror("execve error");
		exit(1);
	}
}

t_child_data	child_data_set(int *pids, int pipe_cnt, t_pipe_data *p_data, \
int pipes[2][2])
{
	t_child_data	c_data;

	c_data.pid = pids[pipe_cnt];
	c_data.pipe_cnt = pipe_cnt;
	c_data.p_d = p_data;
	if (pipe_cnt == 0)
	{
		c_data.fd_in_out[0] = p_data->infile;
		c_data.fd_in_out[1] = pipes[pipe_cnt][1];
		c_data.fd_to_close[0] = pipes[pipe_cnt][0];
		c_data.fd_to_close[1] = 0;
	}
	else
	{
		c_data.fd_in_out[0] = pipes[(pipe_cnt + 1) % 2][0];
		c_data.fd_in_out[1] = p_data->outfile;
		c_data.fd_to_close[0] = pipes[(pipe_cnt + 1) % 2][1];
		c_data.fd_to_close[1] = 0;
	}
	return (c_data);
}

static char	*cmd_path_find(char *cmd, char **environ)
{
	char	**paths_env;
	int		cnt;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	cnt = 0;
	while (ft_strncmp(environ[cnt], "PATH=", 5) != 0)
		cnt++;
	paths_env = ft_split(&(environ[cnt][5]), ':');
	cnt = 0;
	while (paths_env[cnt])
	{
		paths_env[cnt] = ft_strjoin(ft_strjoin(paths_env[cnt], "/"), cmd);
		cnt++;
	}
	while (*paths_env)
	{
		paths_env++;
		if (access(*paths_env, X_OK) == 0)
			return (*paths_env);
	}
	perror("command not found");
	exit(1);
}

static void	io_dup(int *in_out_fd)
{
	if (dup2(in_out_fd[0], 0) == -1)
	{
		perror("dup2 error");
		exit(1);
	}
	if (dup2(in_out_fd[1], 1) == -1)
	{
		perror("dup2 error");
		exit(1);
	}
	fd_arr_close(in_out_fd);
}
