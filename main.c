#include "shell.h"
/**
* main - he does the reading
*
* @ac: argument count
* @av: argument vector
* @envp: environment vector
*
* Return: nothing 0
*/

int main(int ac, char **av, char *envp[])
{
	char *line = NULL, *pathcommand = NULL, *path = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	char **command = NULL, **paths = NULL;
	(void)envp, (void)av;
	if (ac < 1)
		return (-1);
	signal(SIGINT, signalhandle);
	while (1)
	{
		freeArr(command);
		freeArr(paths);
		free(pathcommand);
		usrimmed();
		linesize = getline(&line, &bufsize, stdin);
		if (linesize < 0)
			break;
		info.ln_count++;
		if (line[linesize - 1] == '\n')
			line[linesize - 1] = '\0';
		command = _symbol(line);
		if (command == NULL || *command == NULL || **command == '\0')
			continue;
		if (mytchecker(command, line))
			continue;
		path = findlocatepath();
		paths = _symbol(path);
		pathcommand = pathtesting(paths, command[0]);
		if (!pathcommand)
			perror(av[0]);
		else
			Execute(pathcommand, command);
	}
	if (linesize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}
