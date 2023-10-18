#include "shell.h"

/**
* usrimmed - extract $ to tell user what program is....
*
* Stamps the prompt if the shell is in interactive mode
* ON initializing to take their input
*
* Return: no return
*/
void usrimmed(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;
	if (flags.interactive)
		write(STDERR_FILENO, "$ ", 2);
}
/**
 *signalhandle- continue to maintain the track is interactive mode
 *@m: the signal number
 *Return: nothing
 */

void signalhandle(int m)
{
	(void)m;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
