#include <cstdio>

char tab[1000];

void lower(char[]);
int main(int argc, char *argv[])
{
	lower("AbCdEf123gH");
	printf("AbCdEf123gH -> %s\n", tab);

	return 0;
}

void lower(char t[])
{
	int i = 0;
	while (t[i] != '\0')
	{
		tab[i] = t[i] >= 'A' && t[i] <= 'Z' ? t[i] - 'A' + 'a' : t[i];
		++i; /* using ++ in any subscript above is considered bad programming
			 practice, given the order of evaluation is unspecified */
	}

	tab[i] = '\0';
}