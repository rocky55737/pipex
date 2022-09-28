#include "pipex.h"

void	child(t_p_data *p_data, int fork_cnt)
{
	char	**cmd;
	char	*cmd_path;

	cmd = set_cmd(cmds[fork_cnt];
	cmd_path = find_cmd_path(p_data, cmd[0]);
	dups(p_data, fork_cnt);
	close_pipes(p_data->pipes_fd);
	execve(cmd_path, cmd, env);
}

char **set_cmd(char *cmd_to_set)
{
	char **cmd;

	if (has_two_quotes(cmd_to_set))
		cmd = split_first_sp(rm_quotes(cmd_to_set));
	else
		cmd = ft_split(cmd_to_set, ' ');
	return (cmd);
}

int	has_two_quotes(char *str)
{
	char	*tmp;

	tmp = ft_strchr(str, '\'');
	if (tmp)
	{
		tmp = ft_strchr(tmp + 1, '\'');
		if (tmp)
			return (1);
	}
	tmp = ft_strchr(str, '\"');
	if (tmp)
	{
		tmp = ft_strchr(tmp + 1, '\"');
		if (tmp)
			return (1);
	}
	return (0);
}

char	*rm_quotes(char *str)
{
	
}
