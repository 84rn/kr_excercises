#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include "getline.h"

#define MAXBUF 1000
#define TAB_WIDTH 4

int entab(char *, char *tab_list[]);
int detab(char *, char *tab_list[]);

int main(int argc, char *argv[])
{
	char tab[MAXBUF];

	char **tab_list = argv + 1;

	printf("Enter text:\n");

	while (getline(tab, MAXBUF))
	{
		int len = strlen(tab);
		printf("Original [len: %d]: %s\n", len, tab);
		len = detab(tab, tab_list);
		printf("Detabbed: [len: %d]: %s\n", len, tab);
	}

	while (getline(tab, MAXBUF))
	{
		int len = strlen(tab);
		printf("Original [len: %d]: %s\n", len, tab);


		len = entab(tab, tab_list);
		printf("Entabbed: [len: %d]: %s\n", len, tab);
	}

}

int detab(char *s, char *tab_list[])
{
	int len = 0, added_len = 0, spaces = 0, default_stops = TAB_WIDTH, old_stop = 0, new_stop = 0;
	char c, *t;

	/* Create a copy of the string */
	len = strlen(s);

	if (!(t = (char *)malloc(len + 1)))
		return -1;

	strcpy(t, s);

	new_stop = (*tab_list ? atoi(*tab_list++) : old_stop + default_stops); /* if list is finished, *tablist = NULL */

	for (len = 0;*s = *t; t++, s++, len++)
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
				*s++ = 'r';	
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


int entab(char *s, char *tab_list[])
{
	int len = 0, rem_len = 0, spaces = 0, new_stop = 0, old_stop = 0, default_stops = TAB_WIDTH;
	char *t;

	/* Create a copy of the string */
	len = strlen(s);

	if (!(t = (char *)malloc(len + 1)))
		return -1;

	strcpy(t, s);

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
					*s++ = 't';
				}
				while (blanks--)
				{
					*s++ = 'b';
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