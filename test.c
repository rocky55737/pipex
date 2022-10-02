#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char **cmd;

	cmd = (char **)malloc(sizeof(char *) * 3);
	cmd[0] = strdup("cat");
	cmd[1] = strdup("a.txt");
	cmd[2] = 0;

	execve("/bin/cat", cmd, 0);
}