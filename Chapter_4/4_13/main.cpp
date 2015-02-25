#include <cstdio>
#include <cstring>

void reverse(char s[]);

int main(void)
{
	char tab[] = "1234567890qwertyuiop";

	reverse(tab);
	printf("%s\n", tab);
	return 0;
}

void reverse(char s[])
{
	/* Check original length */
	int orig_len = strlen(s);

	/* Save the lost character */
	char lost_char = s[orig_len - 1];

	/* Shorten the string */
	s[orig_len - 1] = '\0';

	/* Get new length */
	int i = strlen(s);

	/* If one char left, the string is short enough, else keep going */
	if (i > 1)
		reverse(s);

	/* Add length */
	s[i] = lost_char;
	s[i + 1] = '\0';

	/* Move last character to the beginning */
	while (i)
	{
		char tmp = s[i - 1];
		s[i - 1] = s[i];
		s[i] = tmp;
		--i;
	}
}