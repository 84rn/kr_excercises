#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include "tests.h"

#define _CRT_SECURE_NO_WARNINGS

#define MAXLINE 100

void tests_init(void)
{
	srand(time(NULL));
}

void test_getline(void)
{
	print_test_name(getline);

	char s[MAXLINE] = {};
	int i;

	while (i = getline(s, MAXLINE))
		printf("%d chars in line: %s\n", i, s);
}

void test_itoa_(void)
{
	print_test_name(itoa_);

	char s[100];
	int i;

	for (i = 0; i < 20; i++)
	{
		int j = rand() % 10000 - 5000;
		itoa_(j, s);
		printf("Converting: %d -> %s\n", j, s);
	}
}

void test_atoi_(void)
{
	print_test_name(atoi_);

	char *s[] = { "1556", "+555", "-+345", "+-4234",
		"+ra", "+34ra", "-123asd5", "-9999",
		"543112", "423-ar", "    123", " 123  ", "  124-55",
		"   455+67  ", " - ", "" };

	int i;
	for (i = 0; i < 16; i++)
	{
		int j = atoi_(s[i]);
		printf("Converting: %s -> %d\n", s[i], j);
	}
}

void test_reverse(void)
{
	print_test_name(reverse);

	char s[][100] = { "There ", "should ", "be ", "+-words",
		"+that", "+explain", "the   ", "9way",
		"But", "  I  ", "am23", " tongue  ", "  1tied5",
		"   and+67  ", " -twisted- ", "Where's",
		"those", "words", " ... ", "" };

	int i;
	for (i = 0; i < 20; i++)
	{
		char t[100];
		strcpy(t, s[i]);
		reverse(s[i]);
		printf("Reversing: %s -> %s\n", t, s[i]);
	}
}

void test_strindex_(void)
{
	print_test_name(strindex_);

	char s[] = "A VERY LONG LINE LINE";
	char t[][100] = { "", "A VERY", "VERY", "LONGLINE", \
		"LINE    ", "LIN", "A VERY LONG LINE", "LINELINE", \
		"VERY LONG", "@@@@@", "     ", "123123",
		"LONG LINE  ", "VER", "LI", "VERY LINE" };

	int i;
	for (i = 0; i < 16; i++)
	{
		printf("String %s: %s at index %d\n", s, t[i], strindex_(s, t[i]));
	}
}

void test_getopt(void)
{
	print_test_name(getopt);

	int type;
	char t[100];

	printf("[=A] - a variable to save to [@]\n"
		"[B] - a variable to load from [#]\n"
		"[letters] - a command [^]\n"
		"[-+123.345 - floating point number [0]\n"
		"[-/+1234] - integer [0]\n"
		"[\\n] - new line [|]\n"
		"Other chars will be returned if not recognized as one of the above\n\n");

	while ((type = getopt(t)) != EOF)
	{
		printf("-> OPT: %s [returned: %d (as char: %c)]\n\n", t, type, type);
	}
}
