#include "pipex_bonus.h"

void				multi_pipe(int input_cnt, char **input);
static t_pipe_data	*m_pipe_data_set(int input_cnt, char **input);
static int			m_infile_open(char *infile_path);
static int			m_outfile_open(char *outfile_path);

void	multi_pipe(int input_cnt, char **input)
{
	t_pipe_data	*p_data;

	p_data = m_pipe_data_set(input_cnt, input);
	m_pipe(p_data);
	free_all(p_data);
}
static void	m_pipe_data_set(int input_cnt, char **input)
{
	t_pipe_data	*p_data;

	p_data = (t_pipe_data *)malloc(sizeof(t_pipe_data));
	if (p_data == 0)
		{
			perror("MALLOC P_DATA ERROR: ");
			exit(1);
		}
	p_data->infile = m_infile_open();
	p_data->outfile = m_outfile_open(input[input_cnt - 1]);
	p_data->cmd_cnt = input_cnt - 3;
	p_data->cmd = &(input[2]);
	return (p_data);
}

static int	m_infile_open(char *infile_path)
{
	int	fd;

	fd = open(infile_path, O_CREAT | O_RDONLY);
	if (fd == 0)
		{
			perror("m_infile_open error: ");
			exit(1);
		}
	return (fd);
}
static int	m_outfile_open(char *outfile_path)
{
	int	fd;

	fd = open(outfile_path, O_CREAT | O_TRUNC | O_WRONLY);
	if (fd == 0)
		{
			perror("m_outfile_open error: ");
			exit(1);
		}
	return (fd);
}
