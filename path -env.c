#include "shell.h"

/**
 * pathy - path append; it adds the path to the command directly
 *
 * @command: the user-entered command
 * @path: path command
 * Return: the buffer that includes it on my track order on success
 */
char *pathy(char *path, char *command)
{
    char *buff;
    size_t i = 0, j = 0;

    if (command == 0)
        command = "";

    if (path == 0)
        path = "";

    buff = malloc(sizeof(char) * (stringlen(path) + stringlen(command) + 2));
    if (!buff)
        return (NULL);

    while (path[i])
    {
        buff[i] = path[i];
        i++;
    }

    if (path[i - 1] != '/')
    {
        buff[i] = '/';
        i++;
    }
    while (command[j])
    {
        buff[i + j] = command[j];
        j++;
    }
    buff[i + j] = '\0';
    return (buff);
}

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
