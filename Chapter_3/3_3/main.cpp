#include <cstdio>
#include <cctype>
#include <cstring>

void expand(char in[], char out[]);

int main(void)
{
	char tab_out[1000];
	char tab_in[1000];

	strcpy(tab_in, "c-aa-aabc-f-ra-95-8d-ga-ZZ-a9-6");
	printf("%s\n", tab_in);

	expand(tab_in, tab_out);

	printf("%s\n", tab_out);
}


void expand(char in[], char out[])
{
	int i, j;
	for (i = 0, j = 0; in[i] != '\0'; i++)
	{
		if (in[i + 1] == '-')
		{
			char op1 = in[i];
			char op2 = in[i + 2];

			if (((isdigit(op1) && isdigit(op2)) ||
				(islower(op1) && islower(op2)) ||
				(isupper(op1) && isupper(op2))) &&
				op1 <= op2)
			{
				for (; op1 <= op2;)
					out[j++] = op1++;

				i += 2;  /* +1 at the end of for */
			}
			else
				out[j++] = in[i];
		}
		else
			out[j++] = in[i];
	}

	out[j] = '\0';
}