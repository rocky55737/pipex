#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	int			fd;
	extern char	**environ;
	int			cnt;

	fd = open("./a.txt", O_RDWR);
	if (dup2(fd, 0) == -1)
		printf("dup2 1 error\n");
	if (dup2(fd, STDOUT_FILENO) == -1)
		printf("dup2 2 error\n");
	if (dup2(fd, 2) == -1)
		printf("dup2 3 error\n");
	if (dup2(fd, 4) == -1)
	{
		printf("dup2 4 error\n");
		return (0);
	}
	cnt = 0;
	while (environ[cnt])
	{
		write(1, environ[cnt], strlen(environ[cnt]));
		cnt++;
	}
}