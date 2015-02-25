#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>

#define MAXSTACK 100
#define MAXBUF 100
#define NUMBER '0'
#define COMMAND '^'
#define VAR_SAVE '@'
#define VAR_LOAD '#'

/* Value stack variables and functions */

double value_stack[MAXSTACK];
int sp;                                  // stack pointer initialized to 0

int push(double val);
double pop(void);
double peek();
void clear_stack();
void clone_top();
void print_top();
void swap_top();

/* ungetch() and getch() stuff */

char ch_buffer[MAXBUF];
int bp;                                  // buffer pointer (empty or not)

char getch_buf = -1;

int getch(void);
void ungetch(int c);
void ungets(char s[]);

/* Others */
int getopt(char out[]);
double atof(char s[]);
void init_command(char c[]);

/*
To save a value in variable 'A' - use =A
To load value from variable 'A' - use A
Last printed value is in variable 'Z'
*/
double vars['Z' - 'A' + 1];

int main(void)
{
	char opt[1000];
	int type;
	double op2;

	while ((type = getopt(opt)) != EOF)
	{
		switch (type)
		{
		case COMMAND:
			init_command(opt);
			break;
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
			op2 = pop();
			vars['z' - 'a'] = op2;
			printf("\t%.8g\n", op2);
			break;
		case '%':
			op2 = pop();
			if (op2)
				push((int)pop() % (int)op2);
			else
				printf("Error: divide by 0\n");
			break;
		case VAR_SAVE:
			vars[tolower(opt[1]) - 'a'] = peek();
			break;
		case VAR_LOAD:
			push(vars[tolower(opt[0]) - 'a']);
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

double peek()
{
	if (sp)
		return value_stack[sp - 1];

	return 0.0;
}

int getch(void)
{
	int c;
	if (getch_buf != -1)
	{
		c = getch_buf;
		getch_buf = -1;
		return c;
	}

	return getchar();

}

void ungetch(int c)
{
	getch_buf = c;
}

void ungets(char s[])
{
	int i = strlen(s), j;
	if (bp + i <= MAXBUF)
	for (j = 0; j < i; j++)
		ch_buffer[bp++] = s[j];
	else
		printf("Error: getch() buffer full\n");
}

int getopt(char out[])
{
	int i = 0;
	char c;
	int ret;

	while ((out[0] = c = getch()) == ' ' || c == '\t')
		;
	out[1] = '\0';

	if (c == '=')
	{
		if (isalpha(out[++i] = c = getch()))
		{
			out[++i] = '\0';
			return VAR_SAVE;
		}

		out[i] = '\0';
		if (c != EOF)
			ungetch(c);

		return '=';
	}

	if (isalpha(c))
	{
		while (isalpha(out[++i] = c = getch()))
			;

		out[i] = '\0';

		if (strlen(out) == 1)
			ret = VAR_LOAD;
		else
			ret = COMMAND;

		if (c != EOF && strcmp("print", out))
			ungetch(c);

		return ret;
	}

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


void init_command(char c[])
{
	double op2;

	if (!strcmp("clear", c))
		clear_stack();
	else if (!strcmp("clone", c))
		clone_top();
	else if (!strcmp("print", c))
		print_top();
	else if (!strcmp("swap", c))
		swap_top();
	else if (!strcmp("sin", c))
		push(sin(pop()));
	else if (!strcmp("pow", c))
	{
		op2 = pop();
		push(pow(pop(), op2));
	}
	else if (!strcmp("exp", c))
		push(exp(pop()));
	else
		printf("Error: unknown command \"%s\".\n", c);
}

void clear_stack()
{
	sp = 0;
}
void clone_top()
{
	int i = sp;

	if (!sp)
	{
		printf("Nothing to clone.\n");
		return;
	}

	if (sp + 1 < MAXSTACK)
	{
		double val = value_stack[sp - 1];
		value_stack[sp++] = val;
	}
	else
		printf("Error: cannot clone, insufficient space\n");

}
void print_top()
{
	if (!sp)
	{
		printf("Stack empty.\n");
		return;
	}
	printf("\n");

	int i = sp;
	int j = (sp >= 5 ? 5 : sp), k = 1;

	while (j--)
	{
		printf("%d: %g\n", k++, value_stack[--i]);

	}
}

void swap_top()
{
	if (sp >= 2)
	{
		double tmp = value_stack[sp - 1];
		value_stack[sp - 1] = value_stack[sp - 2];
		value_stack[sp - 2] = tmp;
	}
	else
	{
		printf("Nothing to swap.\n");
	}
}