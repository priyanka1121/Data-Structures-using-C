#include <stdio.h>
#include <stdlib.h>

void push1(int);
void push2(int);
int pop1();
int pop2();
void enqueue();
void dequeue();
void display();
void create();

int s1[50], s2[50];
int top1 = -1, top2 =-1;
int count = 0;

void main()
{
    int ch;
    printf("\n1 Insert Element");
    printf("\n2 Delete Element");
    printf("\n3 Display");
    printf("\n4 Exit");

    create();
    while (1)
    {
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
}

void create(){
    top1 = top2 = -1;
}

//Push the elemnt into stack 1
void push1(int x){
    s1[++top1] = x;
}

//pop or delete the elemnt from stack 1

int pop1(){
    return(s1[top1--]);
}

// to push the elemt into stack 2

void push2(int x){
    s2[++top2] = x;
}

//pop it from stack2

int pop2(){
   return( s2[top2--]);
}

void enqueue(){
    int x;
    printf("Enter data: \n");
    scanf("%d",&x);
    push1(x);
    count++;
}

void dequeue(){
    int i;
    for(i=0;i<=count;i++){
        push2(pop1());
    }
    pop2();
    count--;
    for(i=0;i<=count;i++){
        push1(pop2());
    }

}

void display(){
    int i;
    for(i=0;i<=top1;i++){
        printf("%d\n",s1[i]);
    }
}