#include "main.h"

/**
 * intToString - turns a number into a string
 *
 * @num: number to be converted
 * @str: string
 */

void intToString(int num, char *str)
{
	int i = 0, j;
	char temp;

	while (num > 0)
	{
		str[i++] = '0' + (num % 10);
		num /= 10;
	}
	str[i] = '\0';
	for (j = 0; j < i / 2; j++)
	{
		temp = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = temp;
	}
}

/**
 * _isdigit - check if the character is a digit (0-9)
 *
 *@c: the int to be checked
 *
 * Return: 1 if it is a digit
 *	0 otherwise
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
/**
 * isnumber - checks if string is a positive number
 *
 * @s: string to be checked
 *
 * Return: 1 if it is
 *      0 otherwise
 */
int isnumber(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (!_isdigit(s[i]))
			return (0);
	}
	return (1);
}

/**
 * _atoi - convert string to int
 *
 *@s: string to be converted
 *
 * Return: void
 */

int _atoi(char *s)
{
	unsigned int result = 0, sign = 0, i = 0;

	while (s[i] != '\0')
	{
		if (_isdigit(s[i]))
		{
			result *= 10;
			result += s[i] - '0';
			i++;
			continue;
		}
		if (result != 0)
			break;

		if (s[i] == '-')
		{
			sign++;
			i++;
			continue;
		}
		i++;
	}
	if (sign % 2 != 0)
		result = -result;

	return (result);
}
