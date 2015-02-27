#include <cstring>
#include "getline.h"
#include "readlines.h"


int readlines(char *lines[], char *mem, int maxlines)
{
	int num_lines = 0;
	char line[MAXLINE];
	int len = 0;

	while ((num_lines < maxlines) && (len = getline(line, MAXLINE)))
	{
		lines[num_lines++] = mem;
		strcpy(mem, line);
		mem += len + 1;
	}

	return num_lines;
}