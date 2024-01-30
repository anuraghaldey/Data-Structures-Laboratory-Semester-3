/* This program converts infix expression to postfix expression. This  program assume that there are Five operators: 
(*, /, +, -,^) in infix expression and operands can be of single-digit only. This program will not work for fractional numbers. Further this program does not check whether infix expression is  valid or not in terms of number of operators and operands.*/


#include<stdlib.h>      /* for exit() */
#include<ctype.h>     /* for isdigit(char ) */
#include<string.h>
#include<iostream>
#define SIZE 100
using namespace std;

char stack[SIZE];
int top = -1; 


void push(char item)
{
	if(top == SIZE-1)
	
		cout<<"\nStack Overflow.";
	
	else
	{
		top = top+1;
		stack[top] = item;
	}
    
}




 char pop()
{
	char item ;

	if(top ==-1)
	{
		cout<<"stack under flow: invalid infix expression";
		getchar(); /* underflow may occur for invalid expression where ( and ) are not matched */
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return item;
	}
}
/* define function that is used to determine whether any symbol is operator or not (that is symbol is operand) this function returns 1 if symbol is operator else return 0 */
int is_operator(char symbol)
{	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	  return 1;
	
	else
		return 0;
	
}
/* define a function that is used to assign precedence to operator. Here ^ denotes exponent operator. In this function we assume that higher integer value means higher precedence */
int precedence(char symbol)
{	if(symbol == '^')/* exponent operator, highest precedence*/
	
		return 3;
	
	else if(symbol == '*' || symbol == '/')
	
		return 2;
	
	else if(symbol == '+' || symbol == '-')          /* lowest precedence */
			return 1;
	
	else
	
		return 0;
	
}	

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{ 
	int i, j;
	char item;
	char x;

	push('(');                               /* push '(' onto stack */
	strcat(infix_exp,")");                  /* add ')' to infix expression */

	i=0;
	j=0;
	item=infix_exp[i];         /* initialize before loop*/

	while(item != '\0')        /* run loop till end of infix expression */
	{
		if(item == '(')
		
			push(item);
		
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;              /* add operand symbol to postfix expr */
			j++;
		}
		else if(is_operator(item) == 1)        /* means symbol is operator */
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = x;                  /* so pop all higher precendence operator and */
				j++;
				x = pop();                       /* add them to postfix expresion */
			}
			push(x);
			/* because just above while loop will terminate we have poppped one extra item
			for which condition fails and loop terminates, so that one*/

			push(item);                 /* push current oprerator symbol onto stack */
		}
		else if(item == ')')         /* if current symbol is ')' then */
		{
			x = pop();                   /* pop and keep popping until */
			while(x != '(')                /* '(' encounterd */
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ /* if current symbol is neither operand not '(' nor ')' and nor
			operator */
			cout<<"\nInvalid infix Expression.\n";        /* the it is illegeal  symbol */
			getchar();
			exit(1);
		}
		i++;


		item = infix_exp[i]; /* go to next symbol of infix expression */
	} /* while loop ends here */

	if(top>0)
	{
		cout<<"\nInvalid infix Expression.\n";        /* the it is illegeal  symbol */
		getchar();
		exit(1);
	}


	postfix_exp[j] = '\0'; /* add sentinel else puts() fucntion */
	/* will print entire postfix[] array upto SIZE */

}


int main()
{
	char infix[SIZE], postfix[SIZE];         

	
	cout<<"\n\t ASSUMPTION: The infix expression contains single letter variables and single digit constants only.\n";
	cout<<"\n\t\t Enter Infix expression : ";
	cin>>infix; //(a+b)*(c-d)

	InfixToPostfix(infix,postfix); //call 
	
	cout<<"\n\t\t Postfix Expression: ";
	cout<<postfix;                     

	return 0;
}