#include "main.h"

/**
 * start_shell - main function for the shell
 *
 * @programName: name of the shell
 * @count: number of commands typed
 * @interative: whether the shell is interactive or not
 *
 *
 */
void start_shell(char *programName, int count, int interative)
{
	size_t n;
	char **args;
	char *PATH = NULL, *line = NULL;
	char num[20];
	int command, stat = getline(&line, &n, stdin);
	static int exitstatus;

	if (stat == -1)
	{
		free(line);
		if (interative)
			write(1, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	args = arg_vector(line);
	if (args[0] != NULL)
	{
		command = check_command(args, &PATH, exitstatus, count, programName);
		if (command == 2)
			;
		else if (command == 1)
			exitstatus = run_command(args, environ, PATH);
		else
		{
			intToString(count, num);
			write(2, programName, _strlen(programName));
			write(2, ": ", 2);
			write(2, num, _strlen(num));
			write(2, ": ", 2);
			write(2, args[0], _strlen(args[0]));
			write(2, ": not found\n", 12);
			if (!interative)
			{
				cleanup(args, &PATH);
				exit(127);
			}
		}
	}
	cleanup(args, &PATH);
}
/**
 * fileorpath - checkes if s is file or path
 *
 * @s: string to be checked
 *
 * Return: 1 if path
 * 0 if a file
 */
int fileorpath(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == '/')
			return (1);
	}
	return (0);
}
/**
 * check_command - check if the command exist
 *
 * @args: argument vector
 * @PATH: path
 * @exitstatus: exit status of previous command
 * @c: number of commands typed
 * @pN: name of the shell
 *
 * Return: 2 if builtin
 *	1 exist
 *	0 doesn't exist
 */
int check_command(char **args, char **PATH, int exitstatus, int c, char *pN)
{
	int stat = fileorpath(args[0]);

	if (builtin(args, *PATH, exitstatus, c, pN))
		return (2);
	if (stat)
	{
		*PATH = _strdup(args[0]);
		return (access(args[0], F_OK) + 1);
	}
	if (getPath(args, PATH))
		return (1);

	return (0);
}

/**
 * run_command - execute command
 *
 * @command_args: argument vector
 * @env: environment vector
 * @path: path string
 *
 * Return: exit status of child
 *
 */
int run_command(char **command_args, char *env[], char *path)
{
	int status;
	pid_t processid;

	processid = fork();
	if (processid == -1)
	{
		perror("Error:");
		return (-1);
	}
	else if (processid == 0)
	{
		execve(path, command_args, env);
		return (-1);
	}
	else
	{
		wait(&status);
		return (WEXITSTATUS(status));
	}
}
