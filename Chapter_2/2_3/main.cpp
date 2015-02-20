#include <cstdio>

int htoi(char[]);

int main(void)
{
	printf("0xFFFF =\t%d\n", htoi("0xFFFF"));
	printf("FFFF =\t\t%d\n", htoi("FFFF"));
	printf("0xabCD =\t%d\n", htoi("0xabCD"));
	printf("AbCD =\t\t%d\n", htoi("AbCD"));
	printf("0XBEEF =\t%d\n", htoi("0XBEEF"));
	printf("000BEEF =\t%d\n", htoi("000BEEF"));

	return 0;
}

int htoi(char num[])
{
	int i = 0, n = 0;

	while (num[i] != '\0')
	{
		if (num[i] >= '0' && num[i] <= '9')
		{
			n = 16 * n + num[i] - '0';
		}
		else if (num[i] >= 'A' && num[i] <= 'F')
		{
			n = 16 * n + num[i] - 'A' + 10;
		}
		else if (num[i] >= 'a' && num[i] <= 'f')
		{
			n = 16 * n + num[i] - 'a' + 10;
		}
		else if (num[i] == 'X' || num[i] == 'x')
		{
			n = 0;
		}

		++i;
	}

	return n;
}