#include <cstdio>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(int argc, char *argv[])
{
	unsigned x = 0xF1F;
	unsigned y = 0xAA;

	if (setbits(x, 11, 8, y) != 0xAAF)
		return 1;

	return 0;
}
 
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return (x & ~(~(~0 << n) << (p + 1 - n))) | ((y & ~(~0 << n)) << (p + 1 - n));
	/* clear n bits of x at position p */  /* OR with shifted n rightmost y bits */
}