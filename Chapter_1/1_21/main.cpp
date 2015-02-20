#include <cstdio>

/*
Excercise 1_21 - entab()
Author: B. Bartyzel
*/

#define MAXBUF 1000
#define TAB_WIDTH 4

int getline(char[], int);
void entab(char in[], int len, int blanks);

int main(void)
{
	char tab[MAXBUF];

	printf("Enter text:\n");

	while (getline(tab, MAXBUF))
	{
		printf("Original: %s\n", tab);
		entab(tab, MAXBUF, TAB_WIDTH);
		printf("Detabbed: %s\n", tab);
	}

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


void entab(char in[], int len, int blanks)
{
	char c;
	int i = 0, l = 0, j = 0;
	short spaces = 0;
	int check = 0;

	char out[MAXBUF];
	
	while ((c = in[i]) != '\0' && l < len - 1)
	{
		if (c == ' ')
		{
			if (i % blanks == 0)
			{
				check = 1;
				spaces = blanks - i % blanks;

				for (j = 1; j < blanks; j++)
				if (in[i + j] != ' ')
				{
					check = 0;
					break;
				}
			}
			if (check)
			{
				out[l++] = '\t';
				i += blanks - 1;
				check = 0;
			}
			else
				out[l++] = c;
		}
		else
			out[l++] = c;

		++i;
	}

	out[l] = '\0';
	i = 0;

	while (i < len)
	{
		in[i] = out[i];
		i++;
	}
}