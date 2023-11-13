#include "main.h"
/**
 * builtin - checks if command is builtin
 *
 * @args: argument vector
 * @PATH: path
 * @exitstatus: exit status of previous command
 * @count: number of commands typed
 * @pN: name of the shell
 *
 * Return: 1 if builtin
 *      0 if not
 */
int builtin(char **args, char *PATH, int exitstatus, int count, char *pN)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		exitfunction(args, PATH, exitstatus, count, pN);
		return (1);
	}
	if (_strcmp(args[0], "env") == 0)
	{
		printenv();
		return (1);
	}
	return (0);
}
/**
 * exitfunction - exit command
 *
 * @args: argument vector
 * @PATH: path
 * @exitstatus: exit status of previous command
 * @count: number of commands typed
 * @pN: name of the shell
 */

void exitfunction(char **args, char *PATH, int exitstatus, int count, char *pN)
{
	char num[20];
	char s[1024];

	if (args[1])
	{
		_strcpy(s, args[1]);

		if (isnumber(s))
		{
			cleanup(args, &PATH);
			exit(_atoi(s) % 256);
		}
		intToString(count, num);
		write(2, pN, _strlen(pN));
		write(2, ": ", 2);
		write(2, num, _strlen(num));
		write(2, ": ", 2);
		write(2, "exit: Illegal number: ", 22);
		write(2, s, _strlen(s));
		write(2, "\n", 1);
		return;
	}
	cleanup(args, &PATH);
	exit(exitstatus);
}

/**
 * printenv - env command
 *
 */
void printenv(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
	}
	/* not working*/
}
