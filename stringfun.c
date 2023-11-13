#include "main.h"
/**
 * _strlen - returns the length of string
 *
 *@s: string to be checked
 *
 * Return: length of s
 */

int _strlen(char *s)
{
	char n = s[0];
	int i = 0;

	while (n != '\0')
	{
		i++;
		n = s[i];
	}

	return (i);
}



/**
 * _strcpy - copy string
 *
 *@dest: the string will be copied to
 *@src: the string to be copied
 *
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcat - concats two arrays
 *
 * @dest: destination of concat
 * @src: source array to concat
 *
 * Return: char value
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	for (j = 0; dest[j] != '\0'; j++)
		;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[j + i] = src[i];
	}
	dest[j + i] = '\0';

	return (dest);

}

/**
 * _strcmp - compare 2 strings
 *
 * @s1: first string to be compared
 * @s2: second string to be compared
 *
 * Return: 15 if s1 > s2
 *	-15 if s1 < s2
 *	0 if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] == s2[i])
			continue;
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		return (s1[i] - s2[i]);
	}

	return (0);
}
