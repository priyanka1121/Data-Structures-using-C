#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;          // Data 
    struct node *next; // Address 
};
void main()
{  
    struct node *head;
    int n;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
     struct node *newNode;
     struct node *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    
    if(head == NULL)
    {
        printf("Unable to allocate");
        exit(0);
    }


   
    printf("Enter the data of node : ");
    scanf("%d", &data);

    head->data = data; 
    head->next = NULL; 


    
    temp = head;
    for(i=2; i<=n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        
        if(newNode == NULL)
        {
            printf("Error");
            break;
        }

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data; 
        newNode->next = NULL; 

        temp->next = newNode; 
        temp = temp->next;   
    }
    
    printf("\nData in the list \n");
    

    
    if(head == NULL)
    {
        printf("List is empty.");
        return;
    }
    
    temp = head;
    while(temp != NULL)
    {
        printf("Data = %d\n", temp->data); 
        temp = temp->next;                
    }
    

}
