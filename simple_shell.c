#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

/**
 * main - start
 *
 * Return: 0
 */

int main(void)
{
	char input[MAX_COMMAND_LENGTH];
	int status = system(input);

	while (1)
	{
		printf("$ ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}
		input[strcspn(input, "\n")] = '\0';

		if (status == -1)
		{
			printf("Error executing command\n");
		}
	}
	return (0);
}

