#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
 
int count;
struct node* top;

void push(){ 
    struct node* newnode= NULL;
    int x;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(!newnode){
        printf("Stack Overflow\n");
        
    }

    printf("Enter data: ");
    scanf("%d",&x);
    newnode->data=x;
    newnode->next = top; //set the next pointer of the newnode to point to the current top node of the list
    top = newnode; //updated
    count++;  //stack size increase by 1

}
/* A function to check if the stack is empty or not*/
/*void isEmpty(top){
    return top == NULL;}*/

void peek(){
    if(top != NULL){
        printf("Peek element is: %d\n", top->data);
    }
    else{
        printf("Stack is empty!!n");
    }
}

void pop(){
    struct node* temp;
    if(top == NULL){
        printf("Stack Underflow\n");
       
    }
    temp = top;
    top = top->next; //now top pointing to second node, it will delete link btween first and second node
    free(temp); 
    printf("Node Deleted!!\n");   
}
int size(){
    return count;
}
void display(){
  struct  node* temp ;
  if(top == NULL){
      printf("Stack Undrflow\n");
    }
   else{
       temp = top;
       while(temp != NULL){
           printf("%d\n", temp->data);
           temp = temp->next;
       }
   } 
}
void main()
{
    push();
    push();
    push();
    peek();
    display();
    pop();
    display();
}