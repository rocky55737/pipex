#include "pipex.h"

t_p_data	set_p_data(int ac, char **av, char **env);
int			infile_open(char *infile_path);
int			outfile_open(char *outfile_path);

t_p_data	set_p_data(int ac, char **av, char **env)
{
	t_p_data	*p_data;
	p_data = (t_p_data *)malloc(sizeof(t_p_data));
	if (p_data == 0)
	{
		perror("P_DATA ERR: ");
		exit(1);
    }
	p_data->in_out_fd[0] = infile_open(av[1]);
	p_data->in_out_fd[1] = outfile_open(av[4]);
	p_data->cmds = av[2];
	p_data->cmd_cnt = ac - 3;
	p_data->env = env;
}

int	infile_open(char *infile_path)
{
	int	fd;

	fd = open(av[1], O_RDONLY, 0644);
	return (fd);
}

int	outfile_open(char *outfile_path)
{
	int	fd;

	fd = open(av[4], O_TRUNC | O_RDWR | O_CREAT, 0666);
	return (fd);
}
