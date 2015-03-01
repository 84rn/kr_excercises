#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include "getline.h"

#define MAXBUF 1000
#define TAB_WIDTH 4

int entab(char *, char *tab_list[], int m, int n);
int detab(char *, char *tab_list[], int m, int n);

int main(int argc, char *argv[])
{
	char tab[MAXBUF];

	char **options = argv;
	char c;
	int m = -1, n = -1, preceding_num = 0;

	while (--argc)
	{
		if ((*++options)[0] == '-')
		{
			switch (c = (*++options[0]))
			{
			case 'm':
				if (preceding_num)
				{
					printf("Usage: tab [-n <default width>] [-m <starting col>] [tab list]\n");
					return -1;
				}
				if (isdigit(*(++options)[0]))
				{
					m = atoi(*options);
					--argc;
				}
				else
				{
					printf("Bad argument for option %s\m", *options);
					return -1;
				}
				break;
			case 'n':
				if (preceding_num)
				{
					printf("Usage: tab [-n <default width>] [-m <starting col>] [tab list]\n");
					return -1;
				}
				if (isdigit(*(++options)[0]))
				{
					n = atoi(*options);
					--argc;
				}
				else
				{
					printf("Bad argument for option -n: %s\n", *options);
					return -1;
				}
				break;
			}
		}
		else
			/* if other args before options */
			preceding_num = 1;
	}

	/* Set to the start of the tab list. If m, options becomes NULL */
	options = argv + 1;
	if (n != -1)
		options += 2;

	printf("Enter text:\n");

	while (getline(tab, MAXBUF))
	{
		int len = strlen(tab);
		printf("Original [len: %d]: %s\n", len, tab);
		len = detab(tab, options, m, n);
		printf("Detabbed: [len: %d]: %s\n", len, tab);
	}

	while (getline(tab, MAXBUF))
	{
		int len = strlen(tab);
		printf("Original [len: %d]: %s\n", len, tab);

		len = entab(tab, options, m, n);
		printf("Entabbed: [len: %d]: %s\n", len, tab);
	}
}

int detab(char *s, char *tab_list[], int m, int n)
{
	int len = 0, added_len = 0, spaces = 0, default_stops = TAB_WIDTH, old_stop = 0, new_stop = 0;
	char *t;

	if (m > 0)
		*tab_list = NULL;

	/* Create a copy of the string */
	len = strlen(s);

	if (!(t = (char *)malloc(len + 1)))
		return -1;

	strcpy(t, s);

	if (n > 0)
		default_stops = n;

	new_stop = (m < 0 ? (*tab_list ? atoi(*tab_list++) : old_stop + default_stops) /* if list is finished, *tablist = NULL */ : m);

	for (len = 0; *s = *t; t++, s++, len++)
	{
		if (len + added_len == new_stop)
		{
			old_stop = new_stop;
			new_stop = (*tab_list ? atoi(*tab_list++) : old_stop + default_stops); /* if list is finished, *tablist = NULL */
		}
		if (*t == '\t')
		{
			while ((len + added_len) < new_stop)
			{
				*s++ = ' ';
				added_len++;
			}
			--added_len;
			--s;
		}
	}

	*s = '\0';
	t -= len;

	free(t);

	return added_len + len;
}


int entab(char *s, char *tab_list[], int m, int n)
{
	int len = 0, rem_len = 0, spaces = 0, new_stop = 0, old_stop = 0, default_stops = TAB_WIDTH;
	char *t;

	/* Create a copy of the string */
	len = strlen(s);

	if (!(t = (char *)malloc(len + 1)))
		return -1;

	strcpy(t, s);

	if (m > 0)
		*tab_list = NULL;

	if (n > 0)
		default_stops = n;

	new_stop = (m < 0 ? (*tab_list ? atoi(*tab_list++) : old_stop + default_stops) /* if list is finished, *tablist = NULL */ : m);

	for (len = 0; *s = *t; s++, t++, len++)
	{
		spaces = 0;

		if (len == new_stop)
		{
			old_stop = new_stop;
			new_stop = (*tab_list ? atoi(*tab_list++) : old_stop + default_stops); /* if list is finished, *tablist = NULL */
		}

		if (*t == ' ')
		{
			do
			{
				len++;
				spaces++;
				t++;
			} while (*t == ' ' && (len % new_stop) != 0);

			if (spaces)
			{
				int tabs = spaces / (new_stop - old_stop);
				int blanks = spaces % (new_stop - old_stop);

				while (tabs--)
				{
					rem_len += (new_stop - old_stop) - 1;
					*s++ = '\t';
				}
				while (blanks--)
				{
					*s++ = ' ';
				}

				--s;
				--t;
				--len;
			}
		}
	}

	t -= len;
	free(t);

	return len - rem_len;
}