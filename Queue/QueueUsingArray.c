#include<stdio.h>
#include<stdlib.h>

void insert();
void delete();
void display();
int arr[50],n;
int rear, front = -1;

void main()
{
    int choice;
    while(1)
    {
        printf("1. Insert the element \n");
        printf("2. Delete the element \n");
        printf("3. Display all the elements \n");
        printf("4. Quit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insert(1); 
                break;

            case 2:
                delete();
                break;

            case 3:
                display ();
                break;

            case 4:
                exit(0);

            default:
                printf ("Wrong choice!! \n");
        }
    }
}
void insert(){
    int x;
    if(rear == n-1){
        printf("Overflow!\n");
    }
    /*else if(front == -1 && rear ==-1){
        front,rear=0;
        printf("Enter data: ");
        scanf("%d", &x);
        arr[rear] = x;
    }*/
    else{
        if(front == -1 )
        front = 0;
        printf("Enter data: ");
        scanf("%d", &x);
        rear++;
        arr[rear]=x;
    }
}
void delete(){
    if(front == -1 && rear == -1){
        if(front == -1 && rear == -1){
            printf("Underflow!!\n");
        }
        else if(front == rear){
            front, rear=-1;
        }
        else{
            printf("Deleted element is %d\n", arr[front]);
            front = front +1;
        }
    }
}
void display(){
    for(int i=front; i<=rear; i++){
        printf("Data is %d\n",arr[i]);
    }
}