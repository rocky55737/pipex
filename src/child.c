#include "pipex_bonus.h"

void	child(pid_t *pids, int in, int out, t_pipe_data *p_data);

void	child(pid_t *pids, int in, int out, t_pipe_data *p_data)
{
	char	**command;
	char	*cmd_path;

	if (pids[pipe_cnt] != 0)
		return ;
	command = ft_split(p_data->cmd[pipe_cnt], ' ');
	cmd_path = cmd_path_find(command[1]);
	execve(cmd_path, command, 0);
}