#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    //infile 검사
	if (access(argv[0], R_OK) == -1)
	{
		if (ft_strcmp(argv, "here_doc") == 0)
		else
		{
			return (-1);
		}
	}
}