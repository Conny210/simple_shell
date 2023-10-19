#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 100

/**
 * main - start
 *
 * Return: 0 (success)
 */

int main(void)
{
	char input[MAX_COMMAND_LENGTH];
	char *token = stroke(input, " ");
	char *commanf = token;
	char *arguments[MAX_ARGUMENTS];
	int arg_count = 0;

	while (1)
	{
		printf("SimpleShell> ");
		fgets(input, sizeof(input), stdin);

		if (input[strlen(input) - 1] == '\n')
		{
			input[strlen(input) - 1] = '\0';
		}

		while (token != NULL && arg_count < MAX_ARGUMENTS)
		{
			arguments[arg_count] = token;
			token = strtok(NULL, " ");
			arg_count++;
		}

		arguments[arg_count] = NULL;

		if (command != NULL)
		{
			pid_t pid = fork();

			if (pid < 0)
			{
				perror("Fork failed");
				exit(1);
			} else if (pid == 0)
			{
				if (execvp(command, arguments) == -1)
				{
					perror("Execution failed");
					exit(1);
				}
			} else
			{
				int status;

				waitpid(pid, &status, 0);
			}
		}
	}
	return (0);
}

