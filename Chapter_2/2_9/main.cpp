#include <cstdio>
#include <climits>

char tab[1000];

char* hex2bin(unsigned num);
int bitcount(unsigned x);

int main(int argc, char *argv[])
{
	unsigned x = 0xBB;
	bitcount(x);

	return 0;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
	int b;
	for (b = 0; x != 0; x &= (x - 1))
	{
		printf("x:\t%s\n", hex2bin(x));
		printf("x-1:\t%s\n", hex2bin(x - 1));
		b++;
	}
	printf("Bits: %d\n", b);
	return b;
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