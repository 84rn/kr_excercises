#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

int main(int argc, char *argv[])
{
	char c;
	int(*function)(int) = NULL;	
	char *p = NULL;
	
	p = strrchr(argv[0], '\\');

	if (!p)
		p = argv[0];
	else
		++p;	

	if (!strncmp(p, "lower", 5))
		function = tolower;
	else if (!strncmp(p, "upper", 5))
		function = toupper;
	
	if (!function)
	{
		printf("Please run the program either as \"lower\", or \"upper\"\n");
		return 1;
	}

	while ((c = getchar()) && c != EOF)	
		putchar((*function)(c));
	
}