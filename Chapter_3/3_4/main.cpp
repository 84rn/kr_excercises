#include <cstdio>
#include <cstring>
#include <climits>

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void)
{
	char tab[1000];
	int i = INT_MIN;

	printf("%d\n", i);

	itoa(i, tab);

	printf("%s\n", tab);
}

void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	
	i = 0;
	do
	{
		/* without using abs() */
		s[i++] = (n % 10 >=0 ? n % 10 : -(n % 10)) + '0';
	} while ((n /= 10));

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