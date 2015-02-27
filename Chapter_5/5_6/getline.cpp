#include <cstdio>

int getline(char *s, int lim)
{
	char c;
	int i = 0;

	while (--lim && (c = getchar()) != EOF && ++i && c != '\n')
		*s++ = c;

	if (c == '\n')
		*s++ = c;

	*s = '\0';

	return i;
}
