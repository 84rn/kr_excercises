#include <cstdio>
#include <cctype>

#define MAXBUF 1000
char ch_buf[1000];
int bp;

int getch();
void ungetch(char);
int getfloat(double *);

int main(void)
{
	double a = 0;

	int ret = getfloat(&a);

	printf("a: %g,  ret: %d\n", a, ret);
	return 0;

}

int getfloat(double *p)
{
	char c, sign;
	double power = 1;

	while (isspace(c = getch()))
		;

	if (!isdigit(c) && c != '-' && c != '+' && c == EOF && c != '.')
		return 0;															// 0 for everything except digits / EOF

	sign = (c == '-' ? -1 : 1);

	if (c == '-' || c == '+')
		c = getch();

	if (!isdigit(c) && c != '.')
	{
		if (c != EOF)
			ungetch(c);
		return 0;
	}

	for (*p = 0; isdigit(c); c = getch())
	{
		*p = 10 * *p + c - '0';
	}

	if (c == '.')
		c = getch();
	

	for (; isdigit(c); c = getch())
	{
		*p = 10 * *p + c - '0';
		power *= 10.0;
	}

	if (c != EOF)
		ungetch(c);

	*p *= sign;
	*p /= power;

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