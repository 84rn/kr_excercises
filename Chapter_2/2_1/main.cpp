#include <cstdio>
#include <climits>

int main(void)
{
	printf("Ranges from <limits.h>:\n");
	printf("Range of type unsigned char:\t[%u %u]\n", 0, UCHAR_MAX);
	printf("Range of type signed char:\t[%d %d]\n", SCHAR_MIN, SCHAR_MAX);
	printf("Range of type unsigned short:\t[%u %u]\n", 0, USHRT_MAX);
	printf("Range of type signed short:\t[%d %d]\n", SHRT_MIN, SHRT_MAX);
	printf("Range of type unsigned int:\t[%u %u]\n", 0, UINT_MAX);
	printf("Range of type signed int:\t[%d %d]\n", INT_MIN, INT_MAX);
	printf("Range of type unsigned long:\t[%u %u]\n", 0, ULONG_MAX);
	printf("Range of type signed long:\t[%d %d]\n", LONG_MIN, LONG_MAX);

	return 0;
}