#include<stdlib.h>
#include<stdio.h>
struct node{int data;
struct node*next;};
void sorted_insert(){
    struct node *temp = NULL;
    struct node *newnode;
    int choice = 1;
    struct node*start=NULL;
    while (choice == 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter data:");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (start == NULL)
        {
            start = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("\nWant to enter insert more(press 0 or 1): ");
        scanf("%d", &choice);
    }
    
    printf("\nEnter data in sorted list:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

   
     if (start->data >= newnode->data)
    {
        newnode->next = start;
        start = newnode;
        return;
    }
    temp=start;
    while (temp->next->data <= newnode->data){
        temp = temp->next;
        
    }
    newnode->next = temp->next;
    temp->next = newnode;
    
    
   
   // newnode = start;
   struct node*t=start;
    printf("\nprinting values\n");
    while (t != NULL)
    {
        printf("\n%d", t->data);
        t = t->next;
    }
}
int main(){
    sorted_insert();
}
