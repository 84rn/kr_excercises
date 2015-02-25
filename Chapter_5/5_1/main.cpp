#include <cstdio>
#include <cctype>

#define MAXBUF 1000
char ch_buf[1000];
int bp;

int getch();
void ungetch(char);
int getint(int *);

int main(void)
{
	int a = 0;

	int b = getint(&a);

	printf("a: %d b: %d\n", a, b);
	return 0;

}

int getint(int *p)
{
	char c, sign;

	while (isspace(c = getch()))
		;

	if (!isdigit(c) && c != '-' && c != '+' && c == EOF)
		return 0;															// 0 for everything except digits / EOF

	sign = (c == '-' ? -1 : 1);

	if (c == '-' || c == '+')
		c = getch();

	if (!isdigit(c))
	{
		if (c != EOF)
			ungetch(c);
		return 0;
	}

	for (*p = 0; isdigit(c); c = getch())
	{
		*p = 10 * *p + c - '0';
	}

	if (c != EOF)
		ungetch(c);

	*p *= sign;

	return c;
}

int getch()
{
	return (bp ? ch_buf[--bp] : getchar());
}

void ungetch(char c)
{
	if (bp < MAXBUF)
		ch_buf[bp++] = c;
	else
		printf("Error: char buffer full!\n");
}