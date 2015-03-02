#include <cctype>
#include <cstdio>
#include <cstring>

enum prog_type
{
	TOLOWER,
	TOUPPER,
	NOACTION
};

int main(int argc, char *argv[])
{
	char c;
	int(*function)(int) = NULL;
	char t[1000];
	char *p;

	strcpy(t, argv[0]);
	p = strtok(t, "\\");

	while (p != NULL)
	{
		if (!strncmp(p, "lower", 5))
			function = tolower;
		else if (!strncmp(p, "upper", 5))
			function = toupper;

		p = strtok(NULL, "\\");
	}

	if (!function)
	{
		printf("Please run the program either as \"lower\", or \"upper\"\n");
		return 1;
	}

	while ((c = getchar()) && c != EOF)	
		putchar((*function)(c));
	
}