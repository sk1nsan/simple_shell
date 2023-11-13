#include "main.h"

/**
 * cleanup - frees memory
 *
 * @args: argument vector
 * @PATH: path
 */
void cleanup(char **args, char **PATH)
{
	int i;

	for (i = 0; args[i]; i++)
	{
		if (args[i])
			free(args[i]);
	}
	if (args)
		free(args);
	if (*PATH != NULL)
	{
		free(*PATH);
	}
}
