// C program to convert infix expression to postfix
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stack
{
	int top;
	unsigned cap;
	int* array;
};

struct Stack* createStack( unsigned cap )
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	if (!stack) return NULL;
	stack->top = -1;
	stack->cap = cap;
	stack->array = (int*) malloc(stack->cap * sizeof(int));
	return stack;
}
int isEmpty(struct Stack* stack)
{
	return stack->top == -1 ;
}
char peek(struct Stack* stack)
{
	return stack->array[stack->top];
}
char pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--] ;
	return '$';
}
void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}

int isOperand(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int checkPrecedence(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}

int infixToPostfix(char* exp)
{
	int i, k;

	struct Stack* stack = createStack(strlen(exp));
	if(!stack)return -1 ;

	for (i = 0, k = -1; exp[i]; ++i)
	{
		if (isOperand(exp[i]))
			exp[++k] = exp[i];
		else if (exp[i] == '(')
			push(stack, exp[i]);
		else if (exp[i] == ')')
		{
			while (!isEmpty(stack) && peek(stack) != '(')
				exp[++k] = pop(stack);
			if (!isEmpty(stack) && peek(stack) != '(')
				return -1;			
			else
				pop(stack);
		}
		else 
		{
			while (!isEmpty(stack) &&
				checkPrecedence(exp[i]) <= checkPrecedence(peek(stack)))
				exp[++k] = pop(stack);
			push(stack, exp[i]);
		}

	}

	while (!isEmpty(stack))
		exp[++k] = pop(stack );

	exp[++k] = '\0';
	printf( "%s", exp );
}


int main()
{
	char exp[100000];    
    printf("Enter the infix expression : ");
    scanf("%s",exp);
	infixToPostfix(exp);
	return 0;
}
