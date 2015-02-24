#include <cstdio>
#include <cctype>

double atof(char s[]);

int main(void)
{
	printf("%g\n", atof("13.234e-3"));
	return 0;
}


double atof(char s[])
{
	int i, sign;
	double val = 0.0, power = 1.0, base, epower = 0.0, eval = 1.0;

	/* Remove trailing spaces */
	for (i = 0; s[i] == ' '; i++)
		;
	/* Check sign */
	sign = (s[i] == '-' ? -1 : 1);

	if (s[i] == '+' || s[i] == '-')
		++i;

	for (; isdigit(s[i]); i++)
		val = 10.0 * val + s[i] - '0';

	if (s[i] == '.')
		++i;

	for (; isdigit(s[i]); i++)
	{
		val = 10.0 * val + s[i] - '0';
		power *= 10;
	}

	/* Check for exp */
	if (s[i] == 'e' || s[i] == 'E')
		++i;

	/* Set base depending on the sign */
	base = (s[i] == '-' ? 0.1 : 10);

	if (s[i] == '-' || s[i] == '+')
		++i;

	/* Get the power */
	for (; isdigit(s[i]); i++)
		epower = 10 * epower + s[i] - '0';

	/* Compute the exp value */
	while (epower--)
		eval *= base;

	return sign * val / power * eval;
}