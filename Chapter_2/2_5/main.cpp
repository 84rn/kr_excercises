#include <cstring>
#include <cstdio>

int any(char in[], char delim[]);

int main(void)
{
	if (any("abcdefgh", "efc") != 2)
		return 1;

	if (any("abdefgh", "ijk") != -1)
		return 2;

	if (any("abbdefgh", "EFAfhd") != 3)
		return 3;

	return 0;

}

int any(char in[], char delim[])
{
	int i = 0, j = 0, w = 0, z = 0;
	char c;

	while (in[j++] != '\0');
	--j;
	w = j;

	for (z = 0; delim[z] != '\0'; z++)
	for (i = 0; i < j; i++)
	if (in[i] == delim[z])
		j = i;

	if (w == j)
		return -1;
	else
		return j;
}
