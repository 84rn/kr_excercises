#include <cstdio>
#include <cctype>
#include <cstring>

#define MAXSTACK 100
#define MAXBUF 100
#define NUMBER '0'
#define COMMAND 'c'

/* Value stack variables and functions */

double value_stack[MAXSTACK];
int sp;                                  // stack pointer initialized to 0

int push(double val);
double pop(void);
void clear_stack();
void clone_top();
void print_top();
void swap_top();

/* ungetch() and getch() stuff */

char ch_buffer[MAXBUF];
int bp;                                  // buffer pointer (empty or not)

int getch(void);
void ungetch(int c);

/* Others */
int getopt(char out[]);
double atof(char s[]);
void init_command(char c[]);

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
			printf("\t%.8g\n", pop());
			break;
		case '%':
			op2 = pop();
			if (op2)
				push((int)pop() % (int)op2); 
			else
				printf("Error: divide by 0\n");
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
	int ret;

	while ((out[0] = c = getch()) == ' ' || c == '\t')
		;
	out[1] = '\0';

	if (isalpha(c))
	{
		while (isalpha(out[++i] = c = getch()))
			;

		out[i] = '\0';
	
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
	if (!strcmp("clear", c))
		clear_stack();
	else if (!strcmp("clone", c))
		clone_top();
	else if (!strcmp("print", c))
		print_top();
	else if (!strcmp("swap", c))
		swap_top();
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

	if (sp + 1 <= MAXSTACK)
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