#include <cstdio>
#include "get_token.h"

int main(void)
{
	struct s_token *p = NULL;

	while (p = get_token())
	{
		printf("Token type:\t%s\n", token_type_as_string(p));
		printf("Token value:\t%s\n", p->value);

		free_token(p);
	}

	return 0;
}