#include "pipex_bonus.h"

void	multi_pipe(int input_cnt, char **input);
static void	m_pipe_data_set(int input_cnt, char **input);

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
