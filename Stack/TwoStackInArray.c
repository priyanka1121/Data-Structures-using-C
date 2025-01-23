/* Implement two stacks in one array*/
/* Both stacks are independent but use the same array. 
We need to make sure one stack does not interfere with the other stack and support push and pop operation accordingly.*/
/*Approach space efficient and when the arry is full, then only it will show overflow
1. creat an array
2. create two stacks using that array
3. We can perform both push() and pop() operation in stacks
4. so stack1 (s1) will have push1 and pop1 for op in stack1
5. so stack2 (s2) will have push2 and pop2 for op in stack2
*/
//This program does not take input from user

#include<stdio.h>
#define size 20

int arr[size];
int top1 = -1;
int top2 = size;

void push1(int data)
{
    if(top1<top2-1)
    {
        top1++;
        arr[top1] = data;
    }
    else{
        printf("Stack is full");
    }
}
void push2(int data)
{
    if(top1<top2-1){
        top2--;
        arr[top2] = data;
    }
    else{
        printf("Stack is full");
    }
}
void pop1(){
    if(top1>=0){
        int x = arr[top1];
        top1--;
        printf("%d is deleted\n",x);
    }
    else{
        printf("Stack is Empty\n");
    }
}
void pop2()
{
    if (top2 < size)
    {
        int x = arr[top2];
        top2--;
        printf("%d is deleted\n", x);
    }
    else
    {
        printf("Stack is Empty\n");
    }
}
void print1(){
    int i;
    for(i=top1;i>=0;--i){
        printf("%d\n",arr[i]);
    }
    printf("\n");
}
void print2()
{
    int i;
    for (i = top2; i < size; ++i)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[size];
    int i, e;
    printf("We can only push 20 values\n");
    for(i=1;i<=10;++i){
        push1(i);
        printf("Value pushed in stack is %d\n",i);
    }
    for (i = 11; i <= 20; ++i)
    {
        push2(i);
        printf("Value pushed in stack is %d\n", i);
    }

    print1();
    print2();

    //popping up all the elements in the stack
    //e : no of elemnts
    e = top1+1;
    while(e){
        pop1();
        --e;
    }

    //and then again trying to pop from again from the empty stack

    pop1();
    return 0;
}

