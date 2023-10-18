#include "shell.h"

/**
* out - pivoting or dealing with an exit order
*
* @line: Read input from stdin
* @command: symbolzed cmnds
* Return: no return
*/
void out(char **command, char *line)
{
	free(line);
	freeArr(command);
	exit(0);
}

/**
* built - implementation of built-in functions with handling
*
* @command: symbolzed commands
* @line: read input from stdin
* Return: 1 if executed, 0 if not
*/
int built(char **command, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (strngcomp(*command, builtin.env) == 0)
	{
		envprnt();
		return (1);
	}
	else if (strngcomp(*command, builtin.exit) == 0)
	{
		out(command, line);
		return (1);
	}
	return (0);
}
