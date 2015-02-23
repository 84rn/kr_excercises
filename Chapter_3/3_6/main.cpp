#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main(void)
{
	char tab[1000];
	int i = -256;

	printf("%d\n", i);

	itoa(i, tab, 6);

	printf("%s\n", tab);
}

void itoa(int n, char s[], int w)
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;

	i = 0;
	do
	{
		s[i++] = abs(n % 10) + '0';
		--w;
	} while ((n /= 10));

	while (w-- > 0)
		s[i++] = ' ';
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}


void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}