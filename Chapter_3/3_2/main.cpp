#include <cstdio>

#define ESCAPE_TXT "raz dwa trzy \t\t\t\t\tcztery \npiec\n"

void escape(char in[], char out[]);
void escape_rev(char in[], char out[]);

int main(void)
{
	char tab[1000], tab_rev[1000];

	escape(ESCAPE_TXT, tab);
	printf("%s\n", tab);

	escape_rev(tab, tab_rev);
	printf("%s\n", tab_rev);

	printf("%s\n", ESCAPE_TXT);
}

void escape(char in[], char out[])
{
	int i = 0, j = 0;
	char c;
	while (in[i] != '\0')
		switch ((c = in[i++]))
	{
		case '\t':
			out[j++] = '\\';
			out[j++] = 't';
			break;
		case '\n':
			out[j++] = '\\';
			out[j++] = 'n';
			break;
		default:
			out[j++] = c;
			break;
	}

	out[j] = '\0';
}

void escape_rev(char in[], char out[])
{
	int i = 0, j = 0;
	char c;

	while ((c = in[i++]) != '\0')
	if (c == '\\')
		switch (c = in[i++])
	{
		case 't':
			out[j++] = '\t';
			break;
		case 'n':
			out[j++] = '\n';
			break;
		default:
			out[j++] = '\\';
			out[j++] = c;
			break;
	}
	else
		out[j++] = c;

	out[j] = '\0';
}