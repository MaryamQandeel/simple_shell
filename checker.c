#include "shell.h"
/**
 * mytchecker - checks to see what kind of weather, built-in function
 *
 * @buf: the line derivative of the getline function
 * @cmd: symbolzed input user
 * Return: 1 if cmd excuted 0 if cmd is not executed
 */
int mytchecker(char **cmd, char *buf)
{
	if (built(cmd, buf))
		return (1);
	else if (**cmd == '/')
	{
		Execute(cmd[0], cmd);
		return (1);
	}
	return (0);
}
