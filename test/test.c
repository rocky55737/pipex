#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

extern char **environ;

int main(int argc, char *argv[])
{
	char	**command = (char **)malloc(sizeof(char *) * 3);
	int		idx;
	int		fd;
	int		pipefd[2];


	command[0] = "cat";
	command[1] = "-c";
	command[2] = 0;
	fd = open("./test.txt", O_RDONLY);
	dup2(fd, 0);
	pipe(pipefd);
	close(pipefd[1]);
	dup2(pipefd[0],1);
    if (execve("/bin/cat", command, 0) == -1)
	{
        fprintf(stderr, "프로그램 실행 error: %s\n", strerror(errno));
        return 1;
    }
}