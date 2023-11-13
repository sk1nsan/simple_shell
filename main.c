#include "main.h"
/**
 * main - entry point of the program
 *
 * @argc: number of args
 * @argv: argument vector
 *
 * Return: 0 if success
*/

int main(int argc, char *argv[])
{
size_t count = 1;

(void)argc;

if (isatty(STDIN_FILENO))
{
	while (1)
	{
		write(1, "# ", 2);
		start_shell(argv[0], count, 1);
		count++;
	}
}
else
{
	start_shell(argv[0], count, 0);
	while (1)
		start_shell(argv[0], count, 0);
}
exit(EXIT_SUCCESS);
}
