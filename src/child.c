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
	char	*ret;
	int		first_q;
	int		last_q;
	char	which_q;
	int		index;

	index = 0;
	while (str[index] != '\'' || str[index] != '\"')
		index++;
	which_q = str[index];
	first_q = index;
	while (str[index])
		index++;
	while (str[index] != which_q)
		index--;
	last_q = index;
	return (strdup_not_quotes(first_q, last_q, str));
}

char	*strdup_not_quotes(int f_index, int l_index, char *str)
{
	int		src_len;
	char	*duped_str;

	src_len = 0;
	while (src[src_len])
		src_len++;
	duped_str = (char *)malloc(sizeof(char) * (src_len + 1) - 2);
	if (duped_str == 0)
		return (0);
	src_len = 0;
	while (src[src_len])
	{
		if (src_len != f_index && src_len != l_index)
		{
			duped_str[src_len] = src[src_len];
			src_len++;
		}
	}
	duped_str[src_len] = 0;
	return (duped_str);
}
