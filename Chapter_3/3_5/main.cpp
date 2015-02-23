#include <cstdio>
#include <cstring>
#include <cmath>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
	char tab[1000];
	int b = -25236;
	
	itob(b, tab, 16);

	printf("%s\n", tab);

	return 0;
}


void itob(int n, char s[], int b)
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;

	i = 0;
	do
	{
		char c = abs(n % b) < 10 ? '0' : 'A' - 10;
		s[i++] = abs(n % b) + c;
	} while ((n /= b));

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