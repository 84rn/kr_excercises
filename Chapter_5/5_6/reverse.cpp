
void reverse(char *s)
{
	char *t = s, c;
	for (; *t; t++);
	for (--t; s < t; c = *s, *s++ = *t, *t-- = c);
}