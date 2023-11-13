#include "main.h"
/**
 * arg_vector - tokenize input string
 *
 * @line: input string
 *
 * Return: argument vector
*/
char **arg_vector(char *line)
{
	char **args;
	char *line_cpy = _strdup(line);
	int i, j;
	char *s = strtok(line_cpy, " ");
	int max_len = _strlen(s);

	for (i = 0; s; i++)
	{
		s = strtok(NULL, " ");
		if (s && _strlen(s) > max_len)
			max_len = _strlen(s);
	}
	args = malloc(sizeof(char *) * (i + 1));
	args[0] = _strdup(strtok(line, " \n\t"));
	for (j = 1; j < i; j++)
	{
		args[j] = _strdup(strtok(NULL, " \n\t"));
	}
	args[j] = NULL;

	free(line_cpy);
	free(line);

	return (args);
}
