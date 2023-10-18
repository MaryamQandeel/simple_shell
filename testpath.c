#include "shell.h"

/**
 * pathtesting - checks whether path is valid
 *
 * @command: The user-made or entered command
 * @path: symbolized
 *
 * Return: directed in order to succeed
 */
char *pathtesting(char **path, char *command)
{
    int i = 0;
    char *output;

    while (path[i])
    {
        output = pathy(path[i], command);
        if (access(output, F_OK | X_OK) == 0)
            return (output);
        free(output);
        i++;
    }
    return (NULL);
}
