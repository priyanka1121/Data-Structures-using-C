/* A+b = ab+*/
/* This program converts infix expression to postfix expression.
This program assume that there are Five operators: (*, /, +, -,^) 
in infix expression and operands can be of single-digit only.*/
/*ERROR: Not getting the output*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char stack[50];
int top = -1;
int n;
/*This will be the push function for the expression*/
void push(char data){
    if(top>=stack[n]){
        printf("Stack overflow!!\n");
    }
    else{
        top = top+1;
        stack[top] = data;
    }
}
/*Pop the stack*/
char pop(){
    char data;
    if(top<0)
    {
        printf("Stack Underflow!!\n");
        exit(1);
    }
    else{
        data = stack[top];
        top = top-1;
        return(data);
    }
}
/* define function that is used to determine whether any symbol is operator or not
(that is symbol is operand) this fucntion returns 1 if symbol is opreator else return 0 */

int chk_operator(char op){
    if(op == "^" || op == "*" || op == "/" || op =="+" || op =="-"){
        return 1;
    }
    else{return 0;}
}

/*Now a function to check or assign the precendance to operato*/

int precendance(char op){
    if(op == "^"){  //exponenet has higher precedence
        return 3;
    }
    else if(op == "*"|| op=="/"){
        return 2;
    }
    else if(op =="+"|| op =="-"){ //lowest precedence
        return 1;
    }
    else{
        return 0 ;
    }
}

//Now the main conversion function

void convert(char infix[], char postfix[] ){
    int i,j;
    char data;
    char x;
    push('(');   //push initial left paranthesis into the stack first
    strcat(infix, ")");  //add ') in the end of the expression

    //initializing the variables for loop
    i,j=0;
    data = infix[i];

    while(data != '\0'){
        if(data == '('){
            push(data);
        }
        else if((isdigit(data) || isalpha(data))){
            postfix[j] = data; /* add operand symbol to postfix expr */
            j++;
        }
        else if (chk_operator(data) == 1)
        {
            x=pop();
            while(chk_operator(x) == 1 && precendance(x)>=precendance(data))
            {
                postfix[j] = x;
                j++;
                x = pop(); /* because just above while loop will terminate we have oppped one extra item for which condition fails and loop terminates, so that one*/
             }
            push(x);
            push(data);
    }
    else if(data == ')'){
        x = pop();
        while(x != '('){
            postfix[j] = x;
            j++;
            x=pop();
        }
    }
    else{
        printf("Invalid Infix Expression\n");
        exit(1);
    }
    i++;

}
if(top>0){
    printf("Invalid infix expression\n");
    exit(1);
}
if(top<0){
    printf("Invalid infix expression\n");
    exit(0);
}
}

int main(){
    char infix[50],postfix[50];
    printf("Enter infix expression: \n");
    gets(infix);
    convert(infix,postfix);
    printf("Postfix Expression: ");
    puts(postfix);
    return 0;
}
