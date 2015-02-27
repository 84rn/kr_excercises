#include <climits>
#include <cstddef>

static char days_in_months[][13] = {
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
};

int day_of_year(int y, int m, int d)
{
	int leap = y % 4 == 0 && y % 100 != 0 || y % 400 == 0;

	if (y < 0 || m < 0 || d < 0 || m > 12 || !m || !d || d > days_in_months[leap][m])
		return -1;

	int i;
	for (i = 1; i < m; d += days_in_months[leap][i], i++);
	
	return d;
}

int month_day(int y, int year_day, int *m, int *d)
{
	if (y < 0 || year_day < 0 || m == NULL | d == NULL || y > INT_MAX || year_day > 365 || !year_day)
		return -1;

	int leap = y % 4 == 0 && y % 100 != 0 || y % 400 == 0;

	int i;
	for (i = 1; year_day > days_in_months[leap][i]; year_day -= days_in_months[leap][i], i++);
	*m = i;
	*d = year_day;

	return 0;
}