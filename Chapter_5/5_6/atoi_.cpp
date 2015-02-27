#include <cstdio>
#include <cctype>

int atoi_(char *s)
{
	char c;
	int sign = 1, val = 0;

	for (; *s == ' ' || *s == '\t'; s++);

	if (*s == '-' || *s == '+')
		sign = (*s++ == '-' ? -1 : 1);

	while (isdigit(c = *s++))
		val = 10 * val + c - '0';

	return sign * val;
}