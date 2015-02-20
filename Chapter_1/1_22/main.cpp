#include <cstdio>

/*
Excercise 1_22 - fold()
Author: B. Bartyzel
*/

#define MAXBUF 101
#define COL_WIDTH 20

int getline(char[], int);
void fold(char[], char[], int);
void clear_tab(char[]);

int main(void)
{
	char tab_in[MAXBUF];
	char tab_out[MAXBUF];
	int i;

	for (i = 0; i < MAXBUF; i++)
	{
		tab_out[i] = '\0';
	}

	printf("Enter text:\n");

	while (getline(tab_in, MAXBUF))
	{
		clear_tab(tab_out);

		printf("\nOriginal: %s\n", tab_in);

		fold(tab_in, tab_out, COL_WIDTH);

		printf("Folded (width: %2d): \n", COL_WIDTH);
		for(i = 0; i < COL_WIDTH; i++)
			printf("-");
		printf("\n%s\n", tab_out);
		for (i = 0; i < COL_WIDTH; i++)
			printf("-");
		printf("\n");
	}

}

void clear_tab(char tab[])
{
	int i = 0;

	while (tab[i] != '\0')
		tab[i++] = '\0';
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


void fold(char in[], char out[], int col_width)
{
	int i = 0, j = 0, l = 0;
	char c;
	int last_blank_pos = -1;
	int lw = 0;

	while (in[i] == ' ' || in[i] == '\t')
		++i;
	
	while ((c = in[i]) != '\0')
	{
		if (lw == col_width)
		{
			if (in[i] == ' ' || in[i] == '\t')
			{
				j = i;
				while (in[j] == ' ' || in[j] == '\t')
					j++;
				--j;


				out[l] = '\n';
				i = j;
				lw = 0;
			}
			else if (last_blank_pos != -1)
			{
				out[l - lw + last_blank_pos] = '\n';
				out[l] = in[i];
				lw = lw - last_blank_pos - 1 /* for the replaced ' ' */;
			}
			else
			{
				out[l++] = '\n';
				out[l] = in[i];

				lw = 0;
			}
			
			last_blank_pos = -1;
		}
		else
		{
			if (in[i] == ' ' || in[i] == '\t')
				last_blank_pos = lw;

			out[l] = in[i];			
		}

		++i; ++l; ++lw;
	}

	out[l] = '\0';	
}