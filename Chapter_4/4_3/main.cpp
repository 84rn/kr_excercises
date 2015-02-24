#include <cstdio>
#include <cctype>

#define MAXSTACK 100
#define MAXBUF 100
#define NUMBER '0'

/* Value stack variables and functions */

double value_stack[MAXSTACK];
int sp;                                  // stack pointer initialized to 0

int push(double val);
double pop(void);

/* ungetch() and getch() stuff */

char ch_buffer[MAXBUF];
int bp;                                  // buffer pointer (empty or not)

int getch(void);
void ungetch(int c);

/* Others */
int getopt(char out[]);
double atof(char s[]);

int main(void)
{
	char opt[1000];
	int type;
	double op2;

	while ((type = getopt(opt)) != EOF)
	{
		switch (type)
		{
		case NUMBER:
			push(atof(opt));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op2 = pop();
			if (op2)
				push(pop() / op2);
			else
				printf("Error: divide by 0\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		case '%':
			op2 = pop();
			push((int)pop() % (int)op2);
			break;

		default:
			printf("Error: unknown command %s\n", opt);
			break;

		}
	}

	return 0;
}

int push(double val)
{
	if (sp < MAXSTACK)
		value_stack[sp++] = val;
	else
		printf("Error: stack full (%d elements)\n", sp);

	return sp;
}

double pop(void)
{
	if (sp)
		return value_stack[--sp];

	printf("Error: stack empty\n");
	return 0.0;
}

int getch(void)
{
	return (bp ? ch_buffer[--bp] : getchar());
}

void ungetch(int c)
{
	if (bp < MAXBUF)
		ch_buffer[bp++] = c;
	else
		printf("Error: getch() buffer full\n");
}

int getopt(char out[])
{
	int i = 0;
	char c;

	while ((out[0] = c = getch()) == ' ' || c == '\t')
		;
	out[1] = '\0';
	
	if (!isdigit(c) && c != '.' && c != '+' && c != '-')
		return c;								// operator
	
	if (c == '+' || c == '-')
	{
		out[++i] = c = getch();
		if (!isdigit(c))
		{
			out[i] = '\0';
			ungetch(c);
			return out[i - 1];
		}
	}

	if (isdigit(c))
	while (isdigit(out[++i] = c = getch()))
		;
	

	if (c == '.')
	while (isdigit(out[++i] = c = getch()))
		;	

	out[i] = '\0';

	if (c != EOF)
		ungetch(c);

	return NUMBER;
}


double atof(char s[])
{
	int i, sign;
	double val = 0.0, power = 1.0, base, epower = 0.0, eval = 1.0;

	/* Remove trailing spaces */
	for (i = 0; s[i] == ' '; i++)
		;
	/* Check sign */
	sign = (s[i] == '-' ? -1 : 1);

	if (s[i] == '+' || s[i] == '-')
		++i;

	for (; isdigit(s[i]); i++)
		val = 10.0 * val + s[i] - '0';

	if (s[i] == '.')
		++i;

	for (; isdigit(s[i]); i++)
	{
		val = 10.0 * val + s[i] - '0';
		power *= 10;
	}

	/* Check for exp */
	if (s[i] == 'e' || s[i] == 'E')
		++i;

	/* Set base depending on the sign */
	base = (s[i] == '-' ? 0.1 : 10);

	if (s[i] == '-' || s[i] == '+')
		++i;

	/* Get the power */
	for (; isdigit(s[i]); i++)
		epower = 10 * epower + s[i] - '0';

	/* Compute the exp value */
	while (epower--)
		eval *= base;

	return sign * val / power * eval;
}