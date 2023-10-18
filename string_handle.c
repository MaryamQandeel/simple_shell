#include "shell.h"

/**
* stringchar - finds the location of a character in a string
*
* @ch: identify the character location
* @strn: string being checked
* Return: re-signal to the first occurrence of the character
* Or a NULL operation if the character is not detected
*/
char *stringchar(char *strn, char ch)
{
	while (*strn)
	{
		if (*strn == ch)
			return (strn);
		strn++;
	}
	if (!ch)
		return (strn);
	return (NULL);
}

/**
* stringlen - retrieve length of string
*
* @s: string traversal
* Return: length of string return of string traversal
*/
int stringlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

/**
* strngcomp - it does a comparison between two strings
*
* @s_1: paired with s2;
* @s_2: paired with s1;
* Return: Retrieve the difference between the strings
*/
int strngcomp(char *s_1, char *s_2)
{
	int i = 0, output;

	while (*(s_1 + i) == *(s_2 + i) && *(s_1 + i) != '\0')
		i++;

	output = (*(s_1 + i) - *(s_2 + i));

	return (output);
}

/**
* stringdup- duplicate string
*
* @s: redundant
* Return: string recursive guide
*/
char *stringdup(char *s)
{
	char *ptr;
	int i, len;

	if (s == NULL)
		return (NULL);

	len = stringlen(s);

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	for (i = 0; *s != '\0'; s++, i++)
		ptr[i] = s[0];

	ptr[i++] = '\0';
	return (ptr);
}

/**
* strngncmpn - performs an operation comparing two strings of up to n bytes
*
* @s_1: paired with s2
* @s_2: paired with s1
* @n: number of bytes
*
* Return: Retrieve the difference between s1 and also s2
*/
int strngcompn(char *s_1, char *s_2, int n)
{
	int i;

	for (i = 0; s_1[i] && s_2[i] && i < n; i++)
	{
		if (s_1[i] != s_2[i])
			return (s_1[i] - s_2[i]);
	}
	return (0);
}
