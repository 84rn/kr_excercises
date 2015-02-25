#include <cstdio>

void itoa(int n, char s[]);

int main(void)
{
	char t[100];

	itoa(-123, t);
	printf("%s\n", t);
	itoa(16234, t);
	printf("%s\n", t);
	itoa(-1645623, t);
	printf("%s\n", t);
		
	return 0;
}
void itoa(int n, char s[])
{
	int i = 0;					// index of string
	int orig_n = n;				// copy n for index calculation

	if (n < 0)
		i++;								// leave space for sign     

	if (n / 10)
	{
		itoa((n / 10), s);

		if (orig_n < 0)
			orig_n = -orig_n;				// only last rec will add the sign
	}

	while (n /= 10)							// calculate the index (how many digits are there)
		++i;

	if (orig_n < 0)
		s[0] = '-';

	// possible sign, so take abs
	s[i] = (orig_n < 0 ? -orig_n : orig_n) % 10 + '0';
	s[i + 1] = '\0';

}