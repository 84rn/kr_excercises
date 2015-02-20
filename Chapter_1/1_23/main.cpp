#include <cstdio>

#define MAXBUF 1000
#define TAB_WIDTH 4

int getline(char buf[], int lim);

char tab[MAXBUF];

int main(void)
{
	extern char tab[MAXBUF];
	int comment_open = 0;
	int string_open = 0;
	int i = 0;

	while (getline(tab, MAXBUF))
	{
		i = 0;

		while (tab[i] != '\0')
		{
			/* Check for string closing/opening */
			if (tab[i] == '\"')
			{
				/* if \" found, don't close the string */
				if (tab[i - 1] != '\\')
					string_open = !string_open;
			}

			if (!string_open)
			{
				/* If not inside the multiline comment */
				if (!comment_open)
				{
					if (tab[i] == '/' && tab[i + 1] == '/')
					{
						/* Remove the rest of the line for single comment */
						i += 2;
						while (tab[i] != '\0' && tab[i] != '\n')
							++i;
					}
					else if (tab[i] == '/' && tab[i + 1] == '*')
					{
						/* Multiline comment opened */
						comment_open = 1;
						i += 2;
					}
					else
						putchar(tab[i++]);

				}
				else
				{
					while (tab[i] != '\0' && tab[i] != '*' && tab[i + 1] != '/')
						++i;

					/* Continue searching for the end */
					if (tab[i] == '\0')
						continue;

					/* End found */
					if (tab[i] == '*' && tab[i + 1] == '/')
					{
						comment_open = 0;
						i += 2;
					}
					else
					{
						/* tab[i] == '*' or tab[i+1] == '/' */
						++i;
					}
				}
			}
			else
			{
				/* Put whatever found inside " " */
				putchar(tab[i++]);
			}
		}
	}

	return 0;
}


int getline(char buf[], int lim)
{
	char c;
	int i;

	for (i = 0; (i < lim - 1) && (c = getchar()) != EOF && c != '\n'; i++)
		buf[i] = c;

	if (c == '\n')
		buf[i++] = c;

	buf[i] = '\0';

	return i;

}