#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

/**
 * main - start
 *
 * Return: 0
 *
 */

int main(void)
{
	char input[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("#cisfun$ ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)
		{
			break;
		}
		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
			exit(1);
		}

		if (child_pid == 0)
		{
			execlp(input, input, (char *)NULL);
			perror(input);
			exit(1);
		} else
		{
			wait(NULL);
		}
	}
	return (0);
}

