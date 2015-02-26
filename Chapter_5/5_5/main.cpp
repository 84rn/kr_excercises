#include <cstdio>
#include <cstring>
#include <cstddef>
#include <cstdlib>
#include <ctime>

#define print_test(x, y, n, f, r) \
	printf("Testing " #f " (n = %d) : " #x ": %s\n", n, x); \
	printf(#y " = %s -> %" #r "\n\n", y, f(x, y, n));


char * strncpy_(char *s, char *t, size_t n);
char * strncat_(char *s, char *t, size_t n);
int  strncmp_(char *s, char *t, size_t n);

int main(void)
{
	char s1[50] = {};
	char *t1[] = { "one", "two", "three", "four", "tell", "me", "that", "you", "love", "me", "more" };
	char t2[] = "lorem ipsum";
	char t3[] = "three";

	int i;

	srand(time(NULL));

	// strncpy
	for (i = 0; i < 11; i++)
	{
		int n = rand() % 7;
		print_test(s1, t1[i], n, strncpy_, s);
		memset(s1, 0, 50);
	}

	// strncat
	for (i = 0; i < 11; i++)
	{
		int n = rand() % 7;
		memcpy(s1, t2, strlen(t2));
		print_test(s1, t1[i], n, strncat_, s);
		memset(s1, 0, 50);
	}

	// strncmp
	for (i = 0; i < 11; i++)
	{
		int n = rand() % 7;
		memcpy(s1, t3, strlen(t3));
		print_test(s1, t1[i], n, strncmp_, d);
		memset(s1, 0, 50);
	}

	return 0;
}


char * strncpy_(char *s, char *t, size_t n)
{
	char *c = s;

	while (n && (*s++ = *t++))
		--n;
	while (n--)
		*s++ = '\0';
	return c;
}

char * strncat_(char *s, char *t, size_t n)
{
	char *c = s;

	while (*s++);
	--s;

	for (; n && *t; n--)
		*s++ = *t++;
	
	*s = '\0';
	return c;
}

int strncmp_(char *s, char *t, size_t n)
{
	for (; (n - 1) && *s && *t && (*s == *t); --n, ++s, ++t);
	return *s - *t;
}