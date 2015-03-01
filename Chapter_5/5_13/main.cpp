#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include "getline.h"

#define MAXBUF 1000

int main(int argc, char *argv[])
{
	int n = 10, i = 0;
	int lines_filled = 0;
	char line_buf[MAXBUF] = {};

	if (argc >= 2)
	{
		if ((*++argv)[0] == '-' && (*argv++)[1] == 'n' && isdigit((*argv)[0]))
		if (!(n = atoi(*argv)))
			n++;

	}

	printf("Tail with n: %d\n", n);

	char **line_tab = NULL;
	line_tab = (char **)malloc(n * sizeof(char *));

	
	if (!line_tab)
	{
		printf("Not enough memory to hold %d lines\n", n);
		return -1;
	}

	int len;
	while (len = getline(line_buf, MAXBUF))
	{
		if (lines_filled == n)
		{
			free(*line_tab);

			for (i = 1; i < n; i++)			
				line_tab[i - 1] = line_tab[i];	
			lines_filled--;
		}

		char *c = (char *)malloc(len + 1);
		if (!c)
		{
			printf("Out of memory. Printing %d saved lines:\n", lines_filled);
			break;
		}
		strcpy(c, line_buf);

		line_tab[lines_filled] = c;

		if (lines_filled < n)
			lines_filled++;		
	}

	/* Print */

	for (i = 0; i < lines_filled; i++)
	{
		printf("%s", line_tab[i]);
		free(line_tab[i]);
	}

	return 0;
}