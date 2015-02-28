#include <cstdio>
#include <cstdlib>
#include <cctype>
#include "getline.h"

#define MAXLINE 1000
#define MAXSTACK 100


double stack[MAXSTACK];
int sp;

double pop()
{
	if (sp > 0)
		return stack[--sp];
	else
		return 0.0;
}

void push(double v)
{
	if (sp < MAXSTACK)
		stack[sp++] = v;
}

int stack_size(void)
{
	return sp;
}

int main(int argc, char *argv[])
{
	char line[MAXLINE];
	double eval = 0.0;
	double op2;
	
	if (argc == 1)
	{
		printf("Nothing to do.\n");
		return 0;
	}

	while (--argc)
	{
		argv++;

		if (isdigit(**argv))		
			push(atof(*argv));		
		else
		{
			/* possible number with preceding +/- */
			if ((**argv == '-' || **argv == '+') && isdigit(*((*argv) + 1)))
				push(atof(*argv));
			else if (stack_size() >= 2)
				switch (**argv)
			{
				case '-':
					op2 = pop();
					push(pop() - op2);
					break;
				case '+':
					push(pop() + pop());
					break;
				case '*':
					push(pop() * pop());
					break;
				case '/':
					op2 = pop();
					push(pop() / op2);
					break;
				default:
					printf("Unknown command: %s\n", *argv);
					return -1;
					break;
			}
			else
			{
				printf("Error: check your numbers - there's not enough.\n");
				return -1;
			}			
		}
	}

	eval = pop();
	printf("%.2f\n", eval);
	return 0;
}