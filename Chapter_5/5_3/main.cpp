#include <cstdio>

void strcat_(char *s, char *t);

int main(int argc, char *argv[])
{
	char t1[100] = "Raz Dwa trzy ";
	char t2[100] = "Cztery piec";

	printf("%s\n", t1);
	printf("%s\n", t2);

	strcat_(t1, t2);

	printf("%s\n", t1);

	return 0;
}


void strcat_(char *s, char *t)
{
	while (*s++); --s;
	while (*s++ = *t++);
}