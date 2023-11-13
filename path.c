#include "main.h"

/**
 * getPath - return path of the command
 *
 * @args: argument vector
 * @PATH: null initially
 *
 * Return: path
 */
int getPath(char **args, char **PATH)
{
	char *fileName = args[0];
	char *c = _strdup(getenv("PATH"));
	char *s;

	s = strtok(c, ":");
	while (s)
	{
		*PATH = malloc(_strlen(s) + _strlen(fileName) + 2);
		if (*PATH)
		{
			_strcpy(*PATH, s);
			_strcat(*PATH, "/");
			_strcat(*PATH, fileName);
			if (access(*PATH, F_OK) == 0)
			{
				/*i have to see if access returns 0 even if it's a directory*/
				free(c);
				return (1);
			}
		}
		s = strtok(NULL, ":");
		free(*PATH);
	}
	*PATH = NULL;
	free(c);
	return (0);
}
