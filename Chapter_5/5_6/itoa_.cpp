
void itoa_(int n, char *s)
{
	int orig_n;

	if (n < 0)
	{
		*s++ = '-';
		n = -n;
	}

	orig_n = n;

	if (n / 10)
	{
		itoa_((n / 10), s);
		while (n /= 10)
			s++;
	}

	*s++ = orig_n % 10 + '0';
	*s = '\0';

}