#include "shell.h"

/**
* _putchar - registers the character c to stdout
*
* @c: character to be written
* Return: success 1
* For the moment of the error, -1 is returned and errno is set appropriately
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* stringprints - string is printed
*
* @s: assortment to be printed
* Return: charachters number printed
*/
int stringprints(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}

	return (i);
}
