/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:08:49 by rhong             #+#    #+#             */
/*   Updated: 2022/09/21 17:17:19 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
}	t_pipe_data;
typedef struct s_child_data
{
	pid_t		pid;
	int			fd_in_out[2];
	int			fd_to_close[2];
	int			pipe_cnt;
	t_pipe_data	*p_d;
}	t_chlid_data;
int		h_input_err_check(int input_cnt, char **input);
int		m_input_err_check(int input_cnt, char **input);

void	here_doc(int input_cnt, char **input);
void	multi_pipe(int input_cnt, char **input);
void	m_pipe(t_pipe_data *p_data);
void	fd_arr_close(int fd_arr[2]);

#endif
