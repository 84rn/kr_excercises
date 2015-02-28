#include <cstdio>
#include <climits>

#include "day_conversion.h"

int check_day_of_year(unsigned int y, unsigned int m, unsigned int d, int check)
{
	int ret = day_of_year(y, m, d);

	printf("Testing: day_of_year(%d, %d, %d) = %d \t\t", y, m, d, ret);
	if (ret == check)
	{
		printf(" CORRECT!\n");
		return 0;
	}
	else
	{
		printf(" FAILED! Should be: %d\n", check);
		return -1;
	}
}
int test_day_of_year()
{
	int ret = 0;

	int dates[][4] = {
		{ 1988, 11, 20, 325 },
		{ 2033, 5, 15, 135 },
		{ 1023, 4, 10, 100 },
		{ -23, 11, 20, -1 },
		{ 2000, -11, 20, -1 },
		{ 1923, 11, -24, -1 },
		{ 1988, 45, 20, -1 },
		{ 1988, 11, 54, -1 },
		{ 1988, 45, 45, -1 },
		{ 1988, 0, 0, -1 },
		{ INT_MAX + 10, 0, 0, -1 }
	};
	int i = 0;

	while (i < 11 && !(ret = check_day_of_year(dates[i][0], dates[i][1], dates[i][2], dates[i][3])))
		++i;

	return ret;
}

int check_month_day(int y, int yd, int m, int d, int check)
{
	int month = 0, day = 0;

	int ret = month_day(y, yd, &month, &day);

	printf("Testing: month_day(%d, %d) = [%d, %d, ret: %d] \t\t", y, yd, month, day, ret);
	if (ret == check && month == m && day == d)
	{
		printf(" CORRECT!\n");
		return 0;
	}
	else
	{
		printf(" FAILED! Should be: [%d, %d, ret: %d] \n", m, d, check);
		return -1;
	}

}

int test_month_day()
{
	int ret = 0;

	int dates[][5] = {
		{ 1988, 45, 2, 14 },
		{ 2033, 2, 1, 2 },
		{ 1023, 0, 0, 0, -1 },
		{ -23, 11, 0, 0, -1 },
		{ 2000, -11, 0, 0, -1 },
		{ INT_MAX + 10, 11, 0, 0, -1 },
		{ 1988, 340, 12, 5 },
		{ 1987, 340, 12, 6 },
		{ 2013, 56, 2, 25 }
	};
	int i = 0;

	while (i < 9 && !(ret = check_month_day(dates[i][0], dates[i][1], dates[i][2], dates[i][3], dates[i][4])))
		++i;

	return ret;
}