#include "shell.h"
/**
 * findlocatepath - finds path from global environment
 *
 * Return: NULL if the path is not detected, or the path if it is detected
 */
char *findlocatepath(void)
{
    int x = 0;
    char **env = environ, *path = NULL;

    while (*env)
    {
        if (strngcompn(*env, "PATH=", 5) == 0)
        {
            path = *env;
            while (*path && x < 5)
            {
                path++;
                x++;
            }
            return (path);
        }
        env++;
    }
  return (NULL);
}
