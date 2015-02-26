#include <cstdio>

#define MAXLINE 100

int getline(char *s, int lim);
void itoa_(int n, char *s);

int main(void)
{
	char s[MAXLINE] = {};

	while (getline(s, MAXLINE))
		printf("Line: %s\n", s);

	itoa_(-123, s);
	printf("%s\n", s); 

	itoa_(5432, s);
	printf("%s\n", s);

	return 0;
}

int getline(char *s, int lim)
{
	char c;
	int i = 0;

	while (--lim && (c = getchar()) != EOF && ++i && c != '\n')
		*s++ = c;

	if (c == '\n')
		*s++ = c;

	*s = '\0';

	return i;
}


void itoa_(int n, char *s)
{
	int orig_n;

	if (n < 0)
	{
		*s++ = '-';
		n = -n;
	}

	orig_n = n;

	if (n / 10)
	{
		itoa_((n / 10), s);
		while (n /= 10)
		    s++;
	}

	*s++ = orig_n % 10 + '0';
	*s = '\0';

}