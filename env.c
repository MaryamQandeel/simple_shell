#include "shell.h"

/**
 * envprnt - prints environment mix to stdout
 *
 * Return: nothing 0
 */
void envprnt(void)
{
	int x = 0;
	char **envy = environ;

	while (envy[x])
	{
		write(STDOUT_FILENO, (const void *)envy[x], stringlen(envy[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}
