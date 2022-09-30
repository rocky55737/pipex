#include "pipex_bonus.h"

int	input_err(int ac)
{
	if (ac != 5)
	{
		perror("NO FIVE ARGUMENT ERR: ");
		return (1);
	}
	return (0);
}
