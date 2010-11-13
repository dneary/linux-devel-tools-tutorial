#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* Stack structure: array of doubles (256 stack entries should be enough) */
/* We will store the index of the head of the stack and increment it on 
 * push & decrement it on pop */

static int head = -1;
static double stack[256];

enum {
	TOKEN_PLUS = '+',
	TOKEN_MINUS = '-',
	TOKEN_MULTIPLY = '*',
	TOKEN_DIVIDE = '/'
};

/* Print stack */
void dump_stack ()
{
	int i;
	for (i=head; i>=0; i--)
		printf("Stack frame %d: %f\n", i, stack[i]);

	return;
}

/* Push a number onto the top of the stack */
void push(double d)
{
	stack[++head] = d;
	return;
}

/* Pop a number off the stack */
double pop()
{


if(head<0){ printf("You've entered a bad string\n"); exit(0); }
	return stack[head--];

}

double calculate(char *rpn_string)
{
	/* While we still have some string left...*/
	while(rpn_string[0] != '\n' && strlen(rpn_string) > 0) {
		int chk, offset;
		char op_string[20];
		double num;

		chk = sscanf(rpn_string, " %lf %n", &num, &offset);
		/* If we matched a number, push. */
		if (chk > 0) { 
			push(num);
			rpn_string += offset;

		} else { /* Number not found */
			chk = sscanf(rpn_string, " %[+-*/] %n", op_string, &offset);
			/* If we matched tokens, find out which ones, 
			 * apply the operation */
			if (chk > 0) {
				int i, len;
				len = strlen (op_string);
				for (i = 0; i < len; i++) {
					double arg1, arg2;
					arg1 = pop ();
					arg2 = pop ();
					switch (op_string[i]) {
						case TOKEN_PLUS:
							push(arg1 + arg2);
							break;
						case TOKEN_MINUS:
							push(arg1 - arg2);
							break;
						case TOKEN_MULTIPLY:
							push(arg1 * arg2);
							break;
						case TOKEN_DIVIDE:
							push(arg1 / arg2);
							break;
						default:
							assert("Illegal operator character\n");
					}
				}
				rpn_string += offset;
			} else { /*  Token not found */
				/* If there's a parse error, output error message & abort */
				fprintf (stderr, "Parse error in input stream at %s\n", rpn_string);
				exit(1);
			}
		}
	}
	/* At the end of the string, pop, and return.
	 * Warn if head != 0 when we finish. */
	if (head != 0) {
		printf ("WARNING: Stack is not empty after generating "
			"result.\n");
	}
	return pop();
}

int main (void)
{
	char rpn_string[256];
	double result;

	/* Read input from stdin (max length 256) */
	printf("Please enter a string in valid RPN format for calculation:\n");
	fgets(rpn_string, 256, stdin);
	
	printf("Input string is: %s\n", rpn_string);

	/* Parse input string & calculate result */
        result = calculate(rpn_string);
	printf("The result is: %lf\n", result);

	return EXIT_SUCCESS;
}

