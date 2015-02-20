#include <cstdio>
#include <cstring>

void squeeze(char s1[], char s2[]);

int main(void)
{
	char t1[100], t2[10];

	strcpy(t1, "W szczebrzeszynie chrzaszcz brzmi w trzcinie");
	strcpy(t2, "Wcsz");

	printf("Original: %s\n", t1);

	squeeze(t1, t2);

	printf("Squeezed: %s\n", t1);

}
void squeeze(char s1[], char s2[])
{
	int j = 0, i = 0, z = 0;

	for (z = 0; s2[z] != '\0'; z++)
	{
		for (i = 0, j = 0; s1[i] != '\0'; i++)
		if (s1[i] != s2[z])
			s1[j++] = s1[i];

		s1[j] = '\0';
	}
	
}
