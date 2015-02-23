#include <cstdio>
#include <climits>

char tab[1000];

unsigned rightrot(unsigned x, int n);
char* hex2bin(unsigned num);

int main(int argc, char *argv[])
{
	unsigned x = 0xAA;

	printf("X:\t%s\n", hex2bin(x));
	printf("Y:\t%s\n", hex2bin(rightrot(x, 4)));

	x = 0xAF;

	printf("X:\t%s\n", hex2bin(x));
	printf("Y:\t%s\n", hex2bin(rightrot(x, 4)));

	return 0;
}

unsigned rightrot(unsigned x, int n)
{
	unsigned int last_bit = ~((~0U) >> 1);

	int masked = x & ~(~0U << n);

	while (masked)
	{
		x >>= 1;
		if (masked & 1U)
			x = x | last_bit;
		masked >>= 1U;
	}

	return x;
}

char* hex2bin(unsigned num)
{
	extern char tab[1000];

	unsigned int mask = 1 << (sizeof(num)* CHAR_BIT) - 1;
	int i = 0, start = 0;

	while (mask)
	{
		if (num & mask)
		{
			if (!start) start = 1;
			tab[i++] = '1';
		}
		else
			tab[i++] = '0';

		mask >>= 1;
	}
	tab[i] = '\0';

	return tab;
}