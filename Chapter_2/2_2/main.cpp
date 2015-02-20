#include <cstdio>
#define MAX_TAB 10
int getline(char buf[], int lim);

int main(void)
{
	int i = 0;
	char tab[MAX_TAB];
	while (i < MAX_TAB)
		tab[i++] = '\0';
		

	getline(tab, MAX_TAB);
	printf("%s\n", tab);

	return 0;
}

int getline(char buf[], int lim)
{
	char c;
	int i;
	int brk = 0;

	for (i = 0; !brk; i++)
	{
		if ((i < lim - 1))
			if ((c = getchar()) != EOF)
				if (c != '\n')
				{
					buf[i] = c;
				}
				else
					brk = 1;
			else
				brk = 1;
		else
			brk = 1;
	}		

	--i; /* necessary, because of how the for works */

	if (c == '\n')
		buf[i++] = c;

	buf[i] = '\0';

	return i;
}