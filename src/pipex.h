/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:08:49 by rhong             #+#    #+#             */
/*   Updated: 2022/09/27 14:56:29 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "../get_next_line/get_next_line_bonus.h"
# include "../libft/libft.h"

typedef struct s_pipe_data
{
	char	**cmd;
	int		infile;
	int		outfile;
	int		cmd_cnt;
	char	**environ;
}	t_pipe_data;
typedef struct s_child_data
{
	pid_t		pid;
	int			fd_in_out[2];
	int			fd_to_close[2];
	int			pipe_cnt;
	t_pipe_data	*p_d;
}	t_child_data;
int				m_input_err_check(int input_cnt, char **input);

void			multi_pipe(int input_cnt, char **input, char **environ);
void			m_pipe(t_pipe_data *p_data);
void			fd_arr_close(int fd_arr[2]);
void			free_all(t_pipe_data *p_data);

void			child(t_child_data c_data);
t_child_data	child_data_set(int *pids, int pipe_cnt, t_pipe_data *p_data, \
int pipes[2][2]);

#endif
