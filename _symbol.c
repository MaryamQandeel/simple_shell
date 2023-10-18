#include "shell.h"

/**
* _symbol - generates symbols from a specific entry
*
* @line: to be able to access its encoding symbolzed
*
* Return: set of strings
*/
char **_symbol(char *line)
{
	char *buf = NULL, *bufp = NULL, *symb = NULL, *delim = " :\t\r\n";
	char **symbs = NULL;
	int symbolsize = 1;
	size_t index = 0, flag = 0;

	buf = stringdup(line);
	if (!buf)
		return (NULL);
	bufp = buf;

	while (*bufp)
	{
		if (stringchar(delim, *bufp) != NULL && flag == 0)
		{
			symbolsize++;
			flag = 1;
		}
		else if (stringchar(delim, *bufp) == NULL && flag == 1)
			flag = 0;
		bufp++;
	}
	symbs = malloc(sizeof(char *) * (symbolsize + 1));
	symb = strtok(buf, delim);
	while (symb)
	{
		symbs[index] = stringdup(symb);
		if (symbs[index] == NULL)
		{
			free(symbs);
			return (NULL);
		}
		symb = strtok(NULL, delim);
		index++;
	}
	symbs[index] = '\0';
	free(buf);
	return (symbs);
}
