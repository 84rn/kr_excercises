#include <cstdio>

#define swap(t, x, y)   t z = x; \
	x = y;	\
	y = z;

#define print(a, b)  printf(#a " = %d, " #b " = %d\n", a, b)

int main(void)
{
	int value_a = 4, value_b= 3;

	print(value_a, value_b);

	swap(int, value_a, value_b);

	print(value_a, value_b);

	return 0;
}
						
	