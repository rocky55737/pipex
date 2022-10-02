#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av, char **env)
{
	char **awk;

	awk = (char **)malloc(sizeof(char *) * 4);
	awk[0] = strdup("awk");
	awk[1] = strdup("{ print }");
	awk[2] = strdup("a.txt");
	awk[3] = 0;
	execve("/usr/bin/awk", awk, env);
}