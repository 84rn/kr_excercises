#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include "getch.h"
#include "getopt.h"

int getopt(char *out)
{
	int i = 0;
	char c;
	char *t = out;
	int ret;

	while ((*out = c = getch()) == ' ' || c == '\t')
		;
	*++out = '\0';

	/* for tests only */
	if (c == '\n')
	{
		*--out = '\0';
		return NEW_LINE;
	}

	if (c == '=')
	{
		if (isalpha(*out = c = getch()))
		{
			*++out = '\0';
			return VAR_SAVE;
		}

		*out = '\0';
		if (c != EOF)
			ungetch(c);

		return '=';
	}

	if (isalpha(c))
	{
		while (isalpha(*out = c = getch()))
			++out;
		;

		*out = '\0';

		if (strlen(t) == 1)
			ret = VAR_LOAD;
		else
			ret = COMMAND;

		if (c != EOF && strcmp("print", t))
			ungetch(c);

		return ret;
	}

	if (!isdigit(c) && c != '.' && c != '+' && c != '-')
		return c;								// operator

	if (c == '+' || c == '-')
	{
		*out = c = getch();
		if (!isdigit(c))
		{
			*out = '\0';

			ungetch(c);
			return *--out;
		}
		++out;
	}

	if (isdigit(c))
	{
		while (isdigit(*out++ = c = getch()));
		--out;
	}
	
	if (c == '.')
	{
		while (isdigit(*out = c = getch()))
			++out;
	}

	*out = '\0';

	if (c != EOF)
		ungetch(c);

	return NUMBER;
}

