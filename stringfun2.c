#include "main.h"

/**
 * _strdup - allocates space in memory, which contains a copy of the str
 *
 * @str: string to be copied
 *
 * Return: pointer to the copied string
 * or NULL if it fails
 */

char *_strdup(char *str)
{
	int i;
	char *str2;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		;
	str2 = malloc(sizeof(char) * i + 1);
	if (str2 == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		str2[i] = str[i];
	str2[i] = '\0';
	return (str2);

}
