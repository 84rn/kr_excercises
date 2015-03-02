#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include "get_token.h"
#include "linked_list.h"

/*

Solution 6_2 - prints alfabetically orgnized IDENTIFIERS (not only variable names)
	-n - minimal string width

	Test: 6_2.exe < text.txt
*/

int main(int argc, char *argv[])
{
	struct s_token *p = NULL;
	int n = 6;
	s_listnode *list = NULL;

	if (argc == 2 && strcmp("-n", argv[1]) == 0 && isdigit(argv[2][0]))
		n = atoi(argv[2]);

	while (p = get_token())
	{
		if (p->type == IDENTIFIER)
		{
			list = add_list(list, p->value, n);
		}

		free_token(p);
	}

	print_list(list);

	free(list);

	return 0;
}