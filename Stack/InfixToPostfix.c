/* A+b = ab+*/
/* This program converts infix expression to postfix expression.
This program assume that there are Five operators: (*, /, +, -,^) 
in infix expression and operands can be of single-digit only.*/
#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>  /* for isdigit(char ) */
#include <string.h>

#define n 100

/* declared here as global variable because stack[] is used by more than one fucntions */
char stack[n];
int top = -1;

/* define push operation */

void push(char data)
{
    if (top >= n - 1)
    {
        printf("\nStack Overflow.");
    }
    else
    {
        top = top + 1;
        stack[top] = data;
    }
}

/* define pop operation */
char pop()
{
    char data;

    if (top < 0)
    {
        printf("Stack underflow!!!\n");
        /*getchar();*/
        /* underflow may occur for invalid expression */
        /* where ( and ) are not matched */
        /*exit(1);*/
    }
    else
    {
        data = stack[top];
        top = top - 1;
        return (data);
    }
}

/* define function that is used to determine whether any op is operator or not
(that is op is operand)
this fucntion returns 1 if op is opreator else return 0 */

int chk_operator(char op)
{
    if (op == '^' || op == '*' || op == '/' || op == '+' || op == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* define fucntion that is used to assign precendence to operator.Here ^ denotes exponent operator.
  In this fucntion we assume that higher integer value
  means higher precendence */

int precedence(char op)
{
    if (op == '^') /* exponent operator, highest precedence*/
    {
        return (3);
    }
    else if (op == '*' || op == '/')
    {
        return (2);
    }
    else if (op == '+' || op == '-') /* lowest precedence */
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

void InfixToPostfix(char infix[], char postfix[])
{
    int i, j;
    char data;
    char x;

    push('(');              /* push '(' onto stack */
    strcat(infix, ")"); /* add ')' to infix expression */

    i = 0;
    j = 0;
    data = infix[i]; /* initialize before loop*/

    while (data != '\0') /* run loop till end of infix expression */
    {
        if (data == '(')
        {
            push(data);
        }
        else if (isdigit(data) || isalpha(data))
        {
            postfix[j] = data; /* add operand op to postfix expr */
            j++;
        }
        else if (chk_operator(data) == 1) /* means op is operator */
        {
            x = pop();
            while (chk_operator(x) == 1 && precedence(x) >= precedence(data))
            {
                postfix[j] = x; /* so pop all higher precendence operator and */
                j++;
                x = pop(); /* add them to postfix expresion */
            }
            push(x);
            /* because just above while loop will terminate we have
            oppped one extra data
            for which condition fails and loop terminates, so that one*/

            push(data); /* push current oprerator op onto stack */
        }
        else if (data == ')') /* if current op is ')' then */
        {
            x = pop();       /* pop and keep popping until */
            while (x != '(') /* '(' encounterd */
            {
                postfix[j] = x;
                j++;
                x = pop();
            }
        }
        else
        {                                            /* if current op is neither operand not '(' nor ')' and nor
                                                       operator */
            printf("\nInvalid infix Expression.\n"); /* the it is illegeal  op */
            /*getchar();
            exit(1);*/
        }
        i++;

        data = infix[i]; /* go to next op of infix expression */
    }                        /* while loop ends here */
    if (top > 0)
    {
        printf("\nInvalid infix Expression.\n"); /* the it is illegeal  op */
        /*getchar();
        exit(1);*/
    }
    if (top > 0)
    {
        printf("\nInvalid infix Expression.\n"); /* the it is illegeal  op */
        /*getchar();
        exit(1);*/
    }

    postfix[j] = '\0'; /* add sentinel else puts() fucntion */
                           /* will print entire postfix[] array upto n */
}

/* main function begins */
int main()
{
    char infix[n], postfix[n]; /* declare infix string and postfix string */

    
   
    printf("\nEnter Infix expression : ");
    gets(infix);

    InfixToPostfix(infix, postfix); /* call to convert */
    printf("Postfix Expression: ");
    puts(postfix); /* print postfix expression */

    return 0;
}