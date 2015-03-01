#include <cstdio>

#define MAXBUF 100

static char ch_buffer[MAXBUF];
static int bp;


int getch(void)
{
	return (bp ? ch_buffer[--bp] : getchar());
}

void ungetch(int c)
{
	if (bp < MAXBUF)
		ch_buffer[bp++] = c;
	else
		printf("Error: getch() buffer full!\n");
}