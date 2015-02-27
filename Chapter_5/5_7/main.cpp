#include <cstdio>
#include "readlines.h"

#define MAXLINENUM 10

char memory_buf[10000];

int main(void)
{
	char *lines[MAXLINENUM];
	int l, i;

	printf("Write some lines below... (Ctrl-Z & Enter to finish)\n\n");
	while (l = readlines(lines, memory_buf, MAXLINENUM))
	{
		printf("Read %d lines:\n", l);
		for (i = 0; i < l; i++)
			printf("%d:\t%s\n", i + 1, lines[i]);
	}

	return 0;
}