/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:08:49 by rhong             #+#    #+#             */
/*   Updated: 2022/09/27 17:55:13 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "../get_next_line/get_next_line_bonus.h"
# include "../libft/libft.h"

typedef struct s_p_data{
	int		in_out_fd[2];
	int		pipes_fd[2][2];
	char	**cmds;
	int		cmd_cnt;
	char	**env;
	pid_t	*pids;
}	t_p_data;

void		pipex(int ac, char **av, char **env);
void		close_pipes(int fd_arr[2]);
t_p_data	*set_p_data(int ac, char **av, char **env);
int 		input_err(int ac);
void		child(t_p_data *p_data, int fork_cnt);
char 		**set_cmd(char *cmd_to_set);
char		**rm_quotes(char *str);
char		*find_cmd_path(t_p_data *p_data, char *cmd);

#endif
