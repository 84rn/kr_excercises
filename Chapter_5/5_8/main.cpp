#include <cstdio>
#include "tests.h"

int main(void)
{
	int t1 = test_day_of_year();
	printf("\n");
	int t2 = test_month_day();

	if (t1)
	{
		printf("\n\nTEST 1 FAILED\n");
		return 1;
	}
	if (t2)
	{

		printf("\n\nTEST 2 FAILED\n");
		return 2;
	}

	printf("\n\nTESTS OK!\n");
	return 0;
}