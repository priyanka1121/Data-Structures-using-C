#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main()
{
    int choice =1;
    struct node *newnode, *temp, *start;
    start = NULL;
    while(choice){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode -> next = NULL;
        if(start == NULL){
            start = newnode;
            temp = newnode;
        }
        else{
            temp -> next = newnode;
            temp = newnode;
        }
        printf("Do you want to enter more node: ");
        scanf("%d",&choice);
    }
    temp = start;
    while(temp!=NULL){
        printf("Data id: %d\n", temp->data);
        temp = temp -> next;
    }
    
}
