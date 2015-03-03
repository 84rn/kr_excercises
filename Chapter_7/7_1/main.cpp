#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

int main(int argc, char *argv[])
{
	char c;
	int(*function)(int) = NULL;
	char *arg = NULL;
	char *name = NULL;
	char *p = NULL;

	arg = (char *)malloc(strlen(argv[0] + 1));
	strcpy(arg, argv[0]);

	p = strtok(arg, "\\");

	while (p != NULL)
	{
		if (name)
			free(name);
		name = (char *)malloc(strlen(p) + 1);
		strcpy(name, p);

		p = strtok(NULL, "\\");
	}

	if (!strncmp(name, "lower", 5))
		function = tolower;
	else if (!strncmp(name, "upper", 5))
		function = toupper;

	free(name);
	name = NULL;

	if (!function)
	{
		printf("Please run the program either as \"lower\", or \"upper\"\n");
		return 1;
	}

	while ((c = getchar()) && c != EOF)	
		putchar((*function)(c));
	
}