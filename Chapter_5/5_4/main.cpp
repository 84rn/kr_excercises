#include <cstdio>

#define print_test(y, x, f) \
	printf("Testing " #y ": %s\n", y); \
	printf(#x " = %s -> %d\n\n", x, f(y, x));

int strend_(char *s, char *t);

int main(void)
{
	char s[] = "one two three";
	char *t[14] = { "two", "one", "thr", "", "one three", "two three", 
					"one two three", "threeee", "thre", "three ",
					"thre ", "three", "   three   ", "threethree"};
	
	int i;
	for (i = 0; i < 14; i++)
	{
		print_test(s, t[i], strend_);
	}

	return 0;
}


int strend_(char *s, char *t)
{
	char *c = t;

	while (*s && *t)
	{
		for (; *s != *t; s++);

		for (; *s && *s == *t; ++s, ++t);

		if (*s)
			t = c;
	}
	return (!*s && !*t);
}