#include <climits>
#include <cstddef>

static char days_in_months[][13] = {
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
};

int day_of_year(int y, int m, int d)
{
	char(*year)[13] = days_in_months;
	char *month;

	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		year++;

	month = *year;

	if (y < 0 || m < 0 || d < 0 || m > 12 || !m || !d || d > *(month + m))
		return -1;

	while (m--)
		d += *month++;

	return d;
}

int month_day(int y, int year_day, int *m, int *d)
{
	char(*year)[13] = days_in_months;
	char *month;

	if (y < 0 || year_day < 0 || m == NULL | d == NULL || y > INT_MAX || year_day > 365 || !year_day)
		return -1;

	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		year++;

	month = *year;

	int i = 0;
	while (year_day > *month)
	{
		year_day -= *month++;
		i++;
	}

	*m = i;
	*d = year_day;

	return 0;
}