/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:08:49 by rhong             #+#    #+#             */
/*   Updated: 2022/09/17 15:21:42 by rhong            ###   ########.fr       */
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

int		h_input_err_check(int input_cnt, char **input);
int		m_input_err_check(int input_cnt, char **input);

void	here_doc(int input_cnt, char **input);
void	multi_pipe(int input_cnt, char **input);

#endif
