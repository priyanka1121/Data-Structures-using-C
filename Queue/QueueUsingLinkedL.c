#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *f, *r = NULL;
struct node *temp;

void insert();
void delete ();
void display();
void peek();

void main()
{
    int choice;
    while (1)
    {
        printf("1. Insert the element \n");
        printf("2. Delete the element \n");
        printf("3. Display all the elements \n");
        printf("4. Peek value\n");
        printf("5.Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(1);
            break;

        case 2:
            delete ();
            break;

        case 3:
            display();
            break;

        case 4:
            peek();
            break;

        case 5:
            exit (0);

        default:
            printf("Wrong choice!! \n");
        }
    }
}
void insert(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: \n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if(f ==NULL && r ==NULL){
        f = r =newnode;
    }
    else{
        r->next = newnode;
        r = newnode;
    }
}
void delete(){
    
    if(f == NULL && r==NULL){
        printf("Underflow\n");
    }
    else{
        temp = f;
        f = f->next;
        free(temp);
    }
}
void display(){
    temp = f;
    while(temp != NULL){
        printf("Data is %d\n", temp->data);
        temp =  temp->next;
    }
}
void peek(){
    printf("Data at front is:  %d\n", f->data);
}