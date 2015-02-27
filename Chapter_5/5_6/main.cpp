#include <cstdio>
#include "tests.h"

int main(void)
{
	tests_init();

	test_getline();
	test_itoa_();
	test_atoi_();
	test_reverse();
	test_strindex_();
	test_getopt();

	return 0;
}
