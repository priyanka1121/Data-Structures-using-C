#include <stdio.h> //not done
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};



int main(){
    struct node* newnode, *start=NULL, *temp;
    int choice,pos,i=1;
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
    
    printf("Enter the position: ");
    scanf("%d",&pos);
    temp = start;
    while(i<pos-1){
        temp = temp -> next;
        i++;
    }
    
    newnode -> prev = temp;
    temp -> next -> prev = newnode;
    temp -> next = newnode;
    
    
    temp = start;
    while(temp!=NULL){
        printf("Displaying data after the specific insertion");
        printf("Data is: %d\n", temp->data);
        temp= temp->next;
    }
}
    

