#include "shell.h"


/**
* freeArr - free all reserved memory
*
* @Arr: buffer to be released
* Return: no return
*/
void freeArr(char **Arr)
{
	int i = 0;

	if (!Arr || Arr == NULL)
		return;
	while (Arr[i])
	{
		free(Arr[i]);
		i++;
	}
	free(Arr);
}

/**
 *Execute - execute commands used by users
 *
 *@arg:chain from pointers to commands
 *@cmnd: command
 * Return: 0
 */
void Execute(char *cmnd, char **arg)
{
	pid_t pid;
	int status;
	char **env = environ;

	pid = fork();
	if (pid < 0)
		perror(cmnd);
	if (pid == 0)
	{
		execve(cmnd, arg, env);
		perror(cmnd);
		free(cmnd);
		freeArr(arg);
		exit(98);
	}
	else
		wait(&status);
}
