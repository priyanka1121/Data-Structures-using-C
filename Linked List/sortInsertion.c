//Insertion In single sorted linked list in such a way the list remain sorted

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;          // Data 
    struct node *next; // Address 
};
struct node *head;
 struct node *newnode;
struct node *temp;
void insert();
void main()
{  
    
 int i=1; 
 int n;
 int choice=1;
    head = (struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("Unable to allocate");
        exit(0);
    }
     temp = head;
    while(choice==1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

         if(newnode == NULL)
        {
            printf("Error");
            break;
        }

        printf("data: %d: ", i);
        scanf("%d", &newnode->data);

        newnode->next = NULL; 
        temp->next = newnode; 
        temp = temp->next;  
        i++;
         printf("\nWant to add more nodes ");
        scanf("%d", &choice);
    }
    
    printf("\nData in the list \n");
    temp = head;
    while(temp != NULL)
    {
        printf("Data = %d\n", temp->data); 
        temp = temp->next;                
    }
    
      printf("\n insert in a sorted linked list \n");
     
       do 
      {
        insert();
        printf("\nWant to enter insert more(press 1 or 0): ");
        scanf("%d", &choice);
      }while (choice == 1);
      
      printf("\nData in the list \n");
    temp = head;
    while(temp != NULL)
    {
        printf("Data = %d\n", temp->data); 
        temp = temp->next; 
       
    }
    
    }
    void insert(){
    struct node *temp = NULL;
    struct node *newnode;
    
   
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter data:");
        scanf("%d", &newnode->data);
       

    
   
     if (head->data >= newnode->data)
    {
        newnode->next = head;
        head = newnode;
     
    }
    else{
    temp=head;
    while (temp->next->data <= newnode->data)
    {
        temp = temp->next;
        
    }
    newnode->next = temp->next;
    temp->next = newnode;
    printf("Node Inserted!!");
    }
  }
}
