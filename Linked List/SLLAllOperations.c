#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start;
/*fuction declaration of all the operations*/
void insert_begin();
void insert_last();
void insert_locc();
void delete_begin();
void delete_last();
void delete_locc();
void FindLength();
void search();
void sort();
void print();
void reverse();
void insert_in_sort();
void sorted_insert();
void main()
{
    int ch = 0;
    while (ch != 10)
    {
        printf("\nEnter the operation to be performed\n");
        printf("\n1.Insert in the begining\n2.Insert at last\n3.Insert at any specified position\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Show\n8.Find Length\n9.Search\n10.Sort\n11.Reverse\n12.Insertion in sorted way\n");
        scanf("\n%d", &ch);
        switch (ch)
        { /*function calls of all the operations */
        case 1:
            insert_begin();
            break;
        case 2:
            insert_last();
            break;
        case 3:
            insert_locc();
            break;
        case 4:
            delete_begin();
            break;
        case 5:
            delete_last();
            break;
        case 6:
            delete_locc();
            break;
        case 7:
            print();
            break;
        case 8:
            FindLength();
            break;
        case 9:
            search();
            break;
        case 10:
            sort();
            break;
        case 11:
            reverse();
            break;
        case 12:
            insert_in_sort();
            break;
        default:
            printf("Enter valid option");
        }
    }
} /*function definition*/
void insert_begin() // to insert the node at the beginnning of linked list
{
    struct node *p;
    int value;
    p = (struct node *)malloc(sizeof(struct node *));
    if (p == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value\n");
        scanf("%d", &value);
        p->data = value;
        p->next = start;
        start = p;
    }
}
void insert_last() // to insert the node at the last of linked list
{
    struct node *p, *temp;
    int value;
    p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value\n");
        scanf("%d", &value);
        p->data = value;
        if (start == NULL)
        {
            p->next = NULL;
            start = p;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = p;
            p->next = NULL;
        }
    }
}
void insert_locc() // to insert the node at the specified location of linked list
{
    int i, loc, value;
    struct node *p, *temp;
    p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter element value");
        scanf("%d", &value);
        p->data = value;
        printf("\nEnter the location after which you want to insert ");
        scanf("\n%d", &loc);
        temp = start;
        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\ncan't insert\n");
                return;
            }
        }
        p->next = temp->next;
        temp->next = p;
    }
}
void delete_begin() // to delete the node present in the beginning of the linked list
{
    struct node *p;
    if (start == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        p = start;
        start = p->next;
        free(p);
    }
}
void delete_last() // to delete the node present in the last of the linked list
{
    struct node *p, *p1;
    if (start == NULL)
    {
        printf("\nlist is empty");
    }
    else if (start->next == NULL)
    {
        start = NULL;
        free(start);
        printf("\nOnly node of the list deleted ...\n");
    }
    else
    {
        p = start;
        while (p->next != NULL)
        {
            p1 = p;
            p = p->next;
        }
        p1->next = NULL;
        free(p);
    }
}
void delete_locc() // to delete the node present at the specified of the linked list
{
    struct node *p, *p1;
    int loc, i;
    printf("\n Enter the location of the node after which you want to perform deletion \n");
    scanf("%d", &loc);
    p = start;
    for (i = 0; i < loc; i++)
    {
        p1 = p;
        p = p->next;

        if (p == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    p1->next = p->next;
    free(p);
    printf("\nDeleted node %d ", loc + 1);
}
void print() // to print the values in the linked list
{
    struct node *p;
    p = start;
    if (p == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("\nprinting values\n");
        while (p != NULL)
        {
            printf("\n%d", p->data);
            p = p->next;
        }
    }
}
void FindLength() {
    int len = 0;
    while(start != NULL){
        start = start->next;
        len++;
    }
    printf("Linked list length is: %d\n", len);
}

void search(){

    struct node *p;
    int item, i=0;
    p = start;
    if(p==NULL){
        printf("\nEmpty list");
    }
    else
    {
        printf("\nEnter item you want to search: ");
        scanf("%d", &item);
        while(p!=NULL){
            if(p->data==item){
                printf("Item found at location: %d\n ",i+1);
                
            }
            else{
               // printf("Element not found!!\n");
            }
            i++;
            p = p->next;
        }
        
    }
    
}
void sort(){
    struct node *temp1, *temp2, *t, *newNode, *start;
    int n, k, i, j;
    start = NULL;
    printf("Input number of elements in the linked list?");
    scanf("%d", &n);
    printf("Input the elements in the linked list:\n");
    for (i = 1; i <= n; i++)
    {
        if (start == NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &newNode->data);
            newNode->next = NULL;
            start = newNode;
            temp1 = start;
        }
        else
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &newNode->data);
            newNode->next = NULL;
            temp1->next = newNode;
            temp1 = newNode;
        }
    }
    for (i = n - 2; i >= 0; i--)
    {
        temp1 = start;
        temp2 = temp1->next;
        for (j = 0; j <= i; j++)
        {
            if (temp1->data > temp2->data)
            {
                k = temp1->data;
                temp1->data = temp2->data;
                temp2->data = k;
            }
            temp1 = temp2;
            temp2 = temp2->next;
        }
    }
    printf("Sorted order is: \n");
    t = start ;
    while (t != NULL)
    {
        printf("%d\t", t->data);
        t = t->next;
    }
}
void reverse(){
    int size;
    if (size < 2)
    {
        return;
    }
    struct node *present = start;
    struct node *previous = NULL;
    struct node *nextnode = present->next;
    while (present != NULL)
    {
        present->next = previous;
        previous = present;
        present = nextnode;
        if (nextnode != NULL)
        {
            nextnode = nextnode->next;
        }
    }
    start = previous;
    print();
}
void insert_in_sort(){
    struct node *head;
    struct node *newnode,*temp;
    int i = 1;
    int n;
    int choice = 1;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("Unable to allocate");
        exit(0);
    }
    temp = head;
    while (choice == 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        if (newnode == NULL)
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
    while (temp != NULL)
    {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }

    printf("\n insert in a sorted linked list \n");

    do
    {
        sorted_insert();
        printf("\nWant to enter insert more(press 1 or 0): ");
        scanf("%d", &choice);
    } while (choice == 1);

    printf("\nData in the list \n");
    temp = head;
    while (temp != NULL)
    {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
}

void sorted_insert(){
    struct node *temp = NULL;
    struct node *newnode,*head;

    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter data:");
        scanf("%d", &newnode->data);

        if (head->data >= newnode->data)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            temp = head;
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
    

