#include "pipex.h"

void	child(t_p_data *p_data, int fork_cnt);
static void	dups(t_p_data *p_data, int fork_cnt);

void	child(t_p_data *p_data, int fork_cnt)
{
	char	**cmd;
	char	*cmd_path;

	cmd = set_cmd(p_data->cmds[fork_cnt]);
	cmd_path = find_cmd_path(p_data, cmd[0]);
	dups(p_data, fork_cnt);
	close_pipes(p_data->pipes_fd);
	execve(cmd_path, cmd, p_data->env);
}

static void	dups(t_p_data *p_data, int fork_cnt)
{
	if (fork_cnt == 0)
	{
		dup2(p_data->in_out_fd[0], 0);
		dup2(p_data->pipes_fd[1], 1);
	}
	else
	{
		dup2(p_data->pipes_fd[0], 0);
		dup2(p_data->in_out_fd[1], 1);
	}
}
