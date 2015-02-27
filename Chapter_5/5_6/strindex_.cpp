
int strindex_(char *s, char *t)
{
	int i = 0, j = 0;
	char *c = t;

	while (*s && *t)
	{
		for (; *s != *t; s++, i++);
		for (; *s && *t && *s == *t; s++, t++, j++);

		if (*t)
		{
			i += j;
			j = 0;
			t = c;
		}
	}

	return (!*t ? i : -1);
}