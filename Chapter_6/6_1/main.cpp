#include <cstdio>
#include <cctype>
#include "getch.h"


int getword(char *word, int lim);

int main(void)
{
	char t[100];
	int i = 1;

	while (getword(t, 100))
		printf("%d: %s\n", i++, t);

	return 0;
}


int getword(char *word, int lim)
{
	char c, *w = word;

	while (!isalnum(c = getch()) && c != EOF);

	if (c != EOF)
		*w++ = c;

	for (; --lim; w++)
	{
		if (!isalnum(*w = getch()))
		{
			ungetch(*w);
			break;
		}
	}

	*w = '\0';
	return word[0];
}