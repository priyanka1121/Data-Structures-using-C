#include <stdlib.h>
#include <stdio.h>
int stack[10];
int n = sizeof(stack) / sizeof(int);
int top = -1;
void push(int data)
{

    if (stack[top] == n - 1)
    {
        printf("Stack Overflow");
        return;
    }
    top++;
    stack[top] = data;
}
void pop()
{
    if (stack[top] == -1)
    {
        printf("Stack underflow");
        return;
    }
    printf("Element popped=%d\n", stack[top]);
    top--;
}
int main()
{
    char a[] = "{a+(b+c)d+e[k+m*(h+i)]}";
    int flag = 1;
    for (int i = 0; i < a[i]; i++)
    {
        char ch = a[i];
        switch (ch)
        {
        case '[':
        case '{':
        case '(':
            top++;
            stack[top] = ch;
            break;
        case ')':
            if (top != -1 && stack[top] == '(')
            {
                top--;
            }
            else
            {
                flag = 0;
            }
            break;
        case '}':
            if (top != -1 && stack[top] == '{')
            {
                top--;
            }
            else
            {
                flag = 0;
            }
            break;
        case ']':
            if (top != -1 && stack[top] == '[')
            {
                top--;
            }
            else
            {
                flag = 0;
            }
            break;
        }
    }
    if (flag == 1)
    {
        printf("balanced");
    }
    else
    {
        printf("NOT balanced");
    }
}
