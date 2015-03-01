#include <cstdio>

int getline(char *s, int max)
{
	char c;
	int i = 0;
	
	while (--max && (*s++ = c = getchar()) != EOF && ++i && c != '\n');

	if (c == EOF)
		--s;
	*s = '\0';

	return i;
}