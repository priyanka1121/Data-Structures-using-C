#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};



int main(){
    struct node* newnode, *start=NULL, *temp;
    int choice;
    do{
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&newnode ->data);
        newnode -> prev = NULL;
        newnode -> next = NULL;
        if(start == NULL){
            start = newnode;
            temp = start;
        }
        else{
            temp ->prev = newnode;
            newnode -> next = start;
            start = newnode;
        }
        printf("Do you want to enter another node:");
        scanf("%d",&choice);
    } while(choice ==1);
    
    temp = start;
    while(temp!=NULL){
        printf("Data is: %d\n", temp->data);
        temp= temp->next;
    }
}
    

