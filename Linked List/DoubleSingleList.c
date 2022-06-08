#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next, *prev;
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
//void sorted_insert();
void main()
{
    int ch = 0;
    while (ch != 10)
    {
        printf("\nEnter the operation to be performed\n");
        printf("\n1.Insert in the begining\n2.Insert at last\n3.Insert at any specified pos\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Show\n8.Find Length\n9.Search\n10.Sort\n11.Reverse\n");
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
        /*case 12:
            sorted_insert();
            break;*/
        default:
            printf("Enter valid option");
        }
    }
}
/*function definition*/
void print(){
    if (start == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    // Else print the Node's Data
    struct node *temp;
    temp = start;
    while (temp != NULL)
    {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
}
void insert_begin(){
    int data;
    struct node* temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->data = data;
    temp->prev = NULL;
    // Pointer of temp will be assigned to start
    temp->next = start;
    start = temp;
}
void insert_last(){
    int data;
    struct node *temp, *temp2;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->data = data;
    temp->next = NULL;
    temp2 = start;

    // If start is NULL
    if (start == NULL)
    {

        start = temp;
    }

    // Changes Links
    else
    {
        while (temp2->next != NULL)
            temp2 = temp2->next;
        temp->prev = temp2;
        temp2->next = temp;
    }
}
void insert_locc(){
    int data, pos, i = 1;
    struct node *temp, *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;

    // Enter the pos and data
    printf("\nEnter pos : ");
    scanf("%d", &pos);
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    newnode->data = data;
    temp = start;

    // If start==NULL,
    if (start == NULL)
    {
        start = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
    }

    // If pos==1,
    else if (pos == 1)
    {
        newnode->next = start;
        newnode->next->prev = newnode;
        newnode->prev = NULL;
        start = newnode;
    }

    // Change links
    else
    {
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        temp->next->prev = newnode;
    }
}
void delete_begin(){
    struct node *temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else
    {
        temp = start;
        start = start->next;
        if (start != NULL)
            start->prev = NULL;
        free(temp);
    }
}
void delete_last(){
    struct node *temp;
    if (start == NULL)
        printf("\nList is empty\n");
    temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    if (start->next == NULL)
        start = NULL;
    else
    {
        temp->prev->next = NULL;
        free(temp);
    }
}
void delete_locc(){
    int pos, i = 1;
    struct node *temp, *p;
    
    temp = start;

    // If DLL is empty
    if (start == NULL)
        printf("\nList is empty\n");

    // Otherwise
    else
    {
        // pos to be deleted
        printf("\nEnter position : ");
        scanf("%d", &pos);

        // If the pos is the first node
        if (pos == 1)
        {
            p = start;
            start = start->next;
            if (start != NULL)
            {
                start->prev = NULL;
            }
            free(p);
            return;
        }

        // Traverse till pos
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        // Change Links
        p = temp->next;
        if (p->next != NULL)
            p->next->prev = temp;
        temp->next = p->next;

        // Free memory
        free(p);
    }
}
void FindLength(){
    int len = 0;
    while(start != NULL){
        start=start->next;
        len++;
    }
    printf("Linked List length: %d\n", len);
}
void search(){
    struct node *ptr;
    int item, i = 0, flag;
    ptr = start;
    if (ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search?\n");
        scanf("%d", &item);
        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                printf("\nitem found at location %d ", i + 1);
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            printf("\nItem not found\n");
        }
    }

}
void sort(){
    struct node *i, *j,*t;
    int num;
    for (i = start; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                num = j->data;
                j->data = i->data;
                i->data = num;
            }
        }
    }
    printf("Sorted order is: \n");
    t = start;
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
        present->prev = nextnode;
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


