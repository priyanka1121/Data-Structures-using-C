#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node n;

n *create_node(int);
void create();
void ins_at_beg();
void ins_at_end();
void ins_at_pos();
void del_at_beg();
void del_at_end();
void del_at_pos();
void sort();
void search();
void print();
void reverse();

n *new, *ptr, *prev;
n *first = NULL, *last = NULL;
int number = 0;

void main()
{
    int ch;


    printf("1.Insert at beginning \n2.Insert at end\n3.Insert at specific position\n4.Delete at beginning\n 5.Delete at end\n6.Delete at specific location\n7.Sort \n8.Search\n9.Reverse\n10.Print\n11.Exit ");

    while (1)
    {

        printf("\n enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            create();
            break;
        case 1:
            ins_at_beg();
            break;
        case 2:
            ins_at_end();
            break;
        case 3:
            ins_at_pos();
            break;
        case 4:
            del_at_beg();
            break;
        case 5:
            del_at_end();
            break;
        case 6:
            del_at_pos();
            break;
        case 7:
            sort();
            break;
        case 8:
            search();
            break;
        case 9:
            reverse();
            break;
        case 10:
            print();
        case 11:
            exit(0);
            break;
        default:
            printf("\nInvalid choice");
        }
    }
}
/*
 *MEMORY ALLOCATED FOR NODE DYNAMICALLY
 */
n *create_node(int data)
{
    number++;
    new = (n *)malloc(sizeof(n));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    return new;
}
/*
 *ADDS NEW NODE
 */
void create()
{

    int data;

    printf("\nEnter the data you would like to add:");
    scanf("%d", &data);
    new = create_node(data);

    if (first == last && first == NULL)
    {

        first = last = new;
        first->next = last->next = NULL;
        first->prev = last->prev = NULL;
    }
    else
    {
        last->next = new;
        new->prev = last;
        last = new;
        last->next = first;
        first->prev = last;
    }
}
/*
 *INSERTS ELEMENT AT FIRST
 */
void ins_at_beg()
{

    int data;

    printf("\nenter the data to be inserted at first:");
    scanf("%d", &data);
    new = create_node(data);

    if (first == last && first == NULL)
    {
        printf("\ninitially it is empty linked list later insertion is done");
        first = last = new;
        first->next = last->next = NULL;
        first->prev = last->prev = NULL;
    }
    else
    {
        new->next = first;
        first->prev = new;
        first = new;
        first->prev = last;
        last->next = first;
        printf("\n the data is inserted at begining");
    }
}
/*
 *INSERTS ELEMNET AT END
 */
void ins_at_end()
{

    int data;

    printf("\nenter the data that has to be inserted at last:");
    scanf("%d", &data);
    new = create_node(data);

    if (first == last && first == NULL)
    {
        printf("\ninitially the list is empty and now new node is inserted but at first");
        first = last = new;
        first->next = last->next = NULL;
        first->prev = last->prev = NULL;
    }
    else
    {
        last->next = new;
        new->prev = last;
        last = new;
        first->prev = last;
        last->next = first;
    }
}
/*
 *INSERTS THE ELEMENT AT GIVEN POSITION
 */
void ins_at_pos()
{
    int data, pos, len = 0, i;
    n *prevnode;

    printf("\n enter the data that you would like to insert:");
    scanf("%d", &data);
    printf("\n enter the position where you have to enter:");
    scanf("%d", &pos);
    new = create_node(data);

    if (first == last && first == NULL)
    {
        if (pos == 1)
        {
            first = last = new;
            first->next = last->next = NULL;
            first->prev = last->prev = NULL;
        }
        else
            printf("\n empty linked list you cant insert at that particular position");
    }
    else
    {
        if (number < pos)
            printf("\n node cant be inserted as position is exceeding the linkedlist length");

        else
        {
            for (ptr = first, i = 1; i <= number; i++)
            {
                prevnode = ptr;
                ptr = ptr->next;
                if (i == pos - 1)
                {
                    prevnode->next = new;
                    new->prev = prevnode;
                    new->next = ptr;
                    ptr->prev = new;
                    printf("\ninserted at position %d succesfully", pos);
                    break;
                }
            }
        }
    }
}
/*
 *SORTING IS DONE OF ONLY NUMBERS NOT LINKS
 */
void sort()
{
    n *temp;
    int tempdata, i, j;

    if (first == last && first == NULL)
        printf("\nlinked list is empty no elements to sort");
    else
    {
        for (ptr = first, i = 0; i < number; ptr = ptr->next, i++)
        {
            for (temp = ptr->next, j = i; j < number; j++)
            {
                if (ptr->data > temp->data)
                {
                    tempdata = ptr->data;
                    ptr->data = temp->data;
                    temp->data = tempdata;
                }
            }
        }
        for (ptr = first, i = 0; i < number; ptr = ptr->next, i++)
            printf("\n%d", ptr->data);
    }
}
/*
 *DELETION IS DONE
 */
void del_at_pos()
{
    int pos, count = 0, i;
    n *temp, *prevnode;

    printf("\n enter the position which u wanted to delete:");
    scanf("%d", &pos);

    if (first == last && first == NULL)
        printf("\n empty linked list you cant delete");

    else
    {
        if (number < pos)
            printf("\n node cant be deleted at position as it is exceeding the linkedlist length");

        else
        {
            for (ptr = first, i = 1; i <= number; i++)
            {
                prevnode = ptr;
                ptr = ptr->next;
                if (pos == 1)
                {
                    number--;
                    last->next = prevnode->next;
                    ptr->prev = prevnode->prev;
                    first = ptr;
                    printf("%d is deleted", prevnode->data);
                    free(prevnode);
                    break;
                }
                else if (i == pos - 1)
                {
                    number--;
                    prevnode->next = ptr->next;
                    ptr->next->prev = prevnode;
                    printf("%d is deleted", ptr->data);
                    free(ptr);
                    break;
                }
            }
        }
    }
}
/*
 *UPDATION IS DONE FRO GIVEN OLD data
 */
/*void update()
{
    int olddata, newdata, i, f = 0;
    printf("\n enter the dataue old dataue:");
    scanf("%d", &olddata);
    printf("\n enter the dataue new dataue:");
    scanf("%d", &newdata);
    if (first == last && first == NULL)
        printf("\n list is empty no elemnts for updation");
    else
    {
        for (ptr = first, i = 0; i < number; ptr = ptr->next, i++)
        {
            if (ptr->data == olddata)
            {
                ptr->data = newdata;
                printf("dataue is updated to %d", ptr->data);
                f = 1;
            }
        }
        if (f == 0)
            printf("\n no such old dataue to be get updated");
    }
}*/
/*
 *SEARCHING USING SINGLE KEY
 */
void search()
{
    int count = 0, key, i, f = 0;

    printf("\nenter the dataue to be searched:");
    scanf("%d", &key);

    if (first == last && first == NULL)
        printf("\nlist is empty no elemnets in list to search");
    else
    {
        for (ptr = first, i = 0; i < number; i++, ptr = ptr->next)
        {
            count++;
            if (ptr->data == key)
            {
                printf("\n the dataue is found at position at %d", count);
                f = 1;
            }
        }
        if (f == 0)
            printf("\n the dataue is not found in linkedlist");
    }
}
/*
 *DISPLAYING IN BEGINNING
 */
void print()
{
    int i;
    if (first == last && first == NULL)
        printf("\nlist is empty no elemnts to print");
    else
    {
        printf("\n%d number of nodes are there", number);
        for (ptr = first, i = 0; i < number; i++, ptr = ptr->next)
            printf("\n %d", ptr->data);
    }
}
/*
 * DISPLAYING IN REVERSE
 */
void reverse()
{
    int i;
    if (first == last && first == NULL)
        printf("\nlist is empty there are no elments");
    else
    {
        for (ptr = last, i = 0; i < number; i++, ptr = ptr->prev)
        {
            printf("\n%d", ptr->data);
        }
    }
}
void del_at_beg(){
    struct node *temp;
    if (first == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if (first->next == first)
    {
        first = NULL;
        free(first);
        printf("\nnode deleted\n");
    }
    else
    {
        temp = first;
        while (temp->next != first)
        {
            temp = temp->next;
        }
        temp->next = first->next;
        first->next->prev = temp;
        free(first);
        first = temp->next;
    }
}
void del_at_end(){
    struct node *ptr;
    if (first == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if (first->next == first)
    {
        first = NULL;
        free(first);
        printf("\nNode deleted\n");
    }
    else
    {
        ptr = first;
        if (ptr->next != first)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = first;
        first->prev = ptr->prev;
        free(ptr);
        printf("\nNode deleted\n");
    }
}
