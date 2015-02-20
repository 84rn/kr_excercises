#include <cstdio>

/*
	Excercise 1_20 - detab() 
	Author: B. Bartyzel
*/

#define MAXBUF 1000
#define TAB_WIDTH 4

int getline(char[], int);
void detab(char in[], int len, int blanks);

int main(void)
{
	char tab[MAXBUF];

	printf("Enter text:\n");

	while (getline(tab, MAXBUF))
	{
		printf("Original: %s\n", tab);
		detab(tab, MAXBUF, TAB_WIDTH);
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



void detab(char in[], int len, int blanks)
{
	char c;
	int i = 0, l = 0;
	short spaces = 0;

	char out[MAXBUF];

	while ((c = in[i++]) != '\0' && l < len - 1)
	{
		if (c != '\t')
			out[l++] = c;
		else
		{
			spaces = blanks - l % blanks;
			while (spaces-- && (l < len - 1))
				out[l++] = ' ';
		}
	}

	out[l] = '\0';
	i = 0;

	while (i < len)
	{
		in[i] = out[i];
		i++;
	}
}