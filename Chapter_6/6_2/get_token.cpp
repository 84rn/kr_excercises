#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include "get_token.h"
#include "getch.h"

#define MAXTOKEN 1000

struct s_token * new_token()
{
	return (struct s_token *)malloc(sizeof(struct s_token));
}

void free_token(struct s_token *t)
{
	if (t->value)
	{
		free(t->value);
		t->value = NULL;
	}
	free(t);
	t = NULL;
}

struct s_token * get_token()
{
	char t[MAXTOKEN];
	char *w = t;
	char c;
	struct s_token *p = NULL;
	token_type type = EMPTY;
	int lines_open = 0;

	while (isspace(c = *w = getch()));

	if (*w != EOF)
		w++;

	/* Check for comments, strings and preprocessor directives */
	switch (c)
	{
	case '#':

		while ((c = *w++ = getch()) && c != EOF)
		{
			if (c == '\n' && !lines_open)
				break;
			if (c == '\n' && lines_open)
				--lines_open;
			if (c == '\\')
				lines_open++;
		}

		if (c == EOF)
			--w;
		*w = '\0';

		type = PREPROCESSOR;
		break;

	case '\"':

		while ((c = *w++ = getch()) && c != '\"' && c != EOF);

		if (c == EOF)
			--w;
		*w = '\0';

		type = STRING;
		break;
	case '/':
		type = ((*w++ = getch()) == '*' ? MULTI_COMMENT : COMMENT);
		while ((c = *w++ = getch()) &&  c != (type == MULTI_COMMENT ? '/' : '\n') && c != EOF);

		if (c == EOF)
			--w;
		*w = '\0';
		break;

	case EOF:

		break;
	default:

		*w = '\0';
		type = CHARACTER;
		break;
	}

	if (type != EMPTY && strlen(t))
	{
		p = new_token();

		p->value = (char *)malloc((strlen(t) + 1) * sizeof(char));
		strcpy(p->value, t);
		p->type = type;
	}

	return p;
}

char * token_type_as_string(struct s_token *p)
{
	switch (p->type)
	{
	case EMPTY:
		return "EMPTY";
	case VARIABLE:
		return "VARIABLE";
	case PREPROCESSOR:
		return "PREPROCESSOR";
	case POINTER:
		return "POINTER";
	case COMMENT:
		return "COMMENT";
	case MULTI_COMMENT:
		return "MULTI_COMMENT";
	case STRING:
		return "STRING";
	case FUNCTION:
		return "FUNCTION";
	case CHARACTER:
		return "CHARACTER";
	default:
		return "ERROR";
	}
}