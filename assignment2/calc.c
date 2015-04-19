#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "dynamicArray.h"

#define PI 3.14159265358979323846


/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);
	double j = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, (i + j));
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);
	double j = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, (j - i));
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);
	double j = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, (j / i));
}

void multiply(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);
	double j = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, (i * j));
}

void power(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);
	double j = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, pow(j, i));
}

void square(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, pow(i, 2));
}

void cube(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, pow(i, 3));
}

void abs_val(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, fabs(i));
}

void square_root(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, sqrt(i));
}

void exponential(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, exp(i));
}

void natural_log(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, log(i));
}

void base_10_log(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, log10(i));
}

double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0)
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if(strcmp(s, "/") == 0)
			divide(stack);
		else if(strcmp(s, "x") == 0)
			multiply(stack);
		else if(strcmp(s, "^") == 0)
			power(stack);
		else if(strcmp(s, "^2") == 0)
			square(stack);
		else if(strcmp(s, "^3") == 0)
			cube(stack);
		else if(strcmp(s, "abs") == 0)
			abs_val(stack);
		else if(strcmp(s, "sqrt") == 0)
			square_root(stack);
		else if(strcmp(s, "exp") == 0)
			exponential(stack);
		else if(strcmp(s, "ln") == 0)
			natural_log(stack);
		else if(strcmp(s, "log") == 0)
			base_10_log(stack);
		else 
		{
			// FIXME: You need to develop the code here (when s is not an operator)
			// Remember to deal with special values ("pi" and "e")
			if(strcmp(s, "pi") == 0)
			{
				pushDynArr(stack, PI);

			}
			else if(strcmp(s, "e") == 0)
			{
				pushDynArr(stack, exp(1.0));
			}
			else
			{
				double number;
				if(isNumber(s, &number) == 1)
				{
					pushDynArr(stack, number);
				}
			}
		}
	}	//end for 

	/* FIXME: You will write this part of the function (2 steps below) 
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
	result = topDynArr(stack);
	popDynArr(stack);
	printf("The result is %f\n", result);
	return result;
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;

	calculate(argc,argv);

	return 0;
}
