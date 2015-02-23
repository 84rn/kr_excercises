#include <cstdio>
#include <climits>


char tab[1000];

unsigned invert(unsigned x, int p, int n);
char* hex2bin(unsigned num);

int main(int argc, char *argv[])
{
	unsigned x = 0xFABF;
	unsigned inv;

	inv = invert(x, 11, 6);

	printf("Number: %x ->\t%sb\n", x, hex2bin(x));
	printf("Invert: %x ->\t%sb\n\n", inv, hex2bin(inv));

	x = 0xAAAAA;
	inv = invert(x, 18, 19);

	printf("Number: %x ->\t%sb\n", x, hex2bin(x));
	printf("Invert: %x ->\t%sb\n\n", inv, hex2bin(inv));

	return 0;
}

unsigned invert(unsigned x, int p, int n)
{
	return x ^ (~(~0 << n) << (p + 1 - n));
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
		else if (start)
			tab[i++] = '0';

		mask >>= 1;
	}
	tab[i] = '\0';

	return tab;
}