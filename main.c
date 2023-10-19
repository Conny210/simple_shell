#include "simpleShell.h"

/**
 * sig_handler - function checks if Ctrl C is pressed
 * @g: int
 */

void sig_handler(int g)
i{
	if (g == SIGINT)
	{
		_puts("\n#cisfun$ ");
	}
}

/**
* _EOF - function handles the End of File
* @len: return value of getline function
* @f: buffer
*/

void _EOF(int len, char *f)
{
	(void)f;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(f);
		}
		exit(0);
	}
}

/**
 * _isatty - verif if terminal
 */

void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#cisfun$ ");
}

/**
 * main - ...
 *
 * Return: 0 (success)
 */

int main(void)
{
	ssize_t len = 0;
	char *b = NULL, *v, *p, **arv;
	size_t size = 0;
	list_path *head = '\0';
	void (*f)(char **);

	signal(SIGINT, sig_handler);
	while (len != EOF)
	{
		_isatty();
		len = getline(&b, &size, stdin);
		_EOF(len, b);
		arv = splitstring(b, " \n");
		if (!arv || !arv[0])
			execute(arv);
		else
		{
			value = _getenv("PATH");
			head = linkpath(value);
			p = _which(arv[0], head);
			f = checkbuild(arv);
			if (f)
			{
				free(b);
				f(arv);
			}
			else if (!p)
				execute(arv);
			else if (p)
			{
				free(arv[0]);
				arv[0] = p;
				execute(arv);
			}
		}
	}
	free_list(head);
	freearv(arv);
	free(b);
	return (0);
}
