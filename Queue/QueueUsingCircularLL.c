//Have to make menu in main
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
 struct node *f, *r = NULL;
void enqueue(){
   
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode ->next = NULL;
    if((r==NULL)&&(f==NULL)){
        f = r = newnode;
        r -> next = f;
    }
    else{
        r -> next = newnode;
        r = newnode;
        newnode -> next = f;
    }
}
void dequeue(){
    struct node* temp;
    temp = f;
    if((f==NULL)&&(r==NULL)){
        printf("queue is empty");
    }
    else if(f==r){
        f = r= NULL;
        free(temp);
        
    }
    else{
        f = f-> next;
        r -> next = f;
        free(temp);
        printf("Node Deleted\n");
    }
}
void display(){
    struct node *temp;
    temp = f;
    while(temp->next != f){
        printf("Data is: %d\n", temp->data);
        temp=temp->next;
    }
    printf("Data is: %d\n",temp->data);
}
void main()
{
    enqueue();
    enqueue();
    enqueue();
    dequeue();
    enqueue();
    display();
    
    //return 0;
}
