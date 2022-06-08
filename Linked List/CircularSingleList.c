#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *x, *y, *z;

void create();
void ins_at_beg();
void ins_at_pos();
void ins_at_end();
void del_at_beg();
void del_at_pos();
void del_at_end();
void print();
void search();
void sort();
//void update();
void reverse(struct node *p);

void main()
{
    int ch;

    printf("\n1.Creation \n2.Insertion at beginning \n3.Insertion at specific position");
    printf("\n4.Insertion in end \n5.Deletion at beginning \n6.Deletion at specific position");
    printf("\n7.Deletion at end\n8.Print\n9.Search\n10.Sort\n11.Reverse\n12.Exit");
    while (1)
    {
        printf("\n Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            ins_at_beg();
            break;
        case 3:
            ins_at_pos();
            break;
        case 4:
            ins_at_end();
            break;
        case 5:
            del_at_beg();
            break;
        case 6:
            del_at_pos();
            break;
        case 7:
            del_at_end();
            break;
        case 8:
            print();
            break;
        case 9:
            search();
            break;
        case 10:
            sort();
            break;
        case 11:
            reverse(head);
            break;
        default:
            exit(0);
        }
    }
}

/*Function to create a new circular nexted list*/
void create()
{
    int c;

    x = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter the data:");
    scanf("%d", &x->data);
    x->next = x;
    head = x;
    printf("\n If you wish to continue press 1 otherwise 0:");
    scanf("%d", &c);
    while (c != 0)
    {
        y = (struct node *)malloc(sizeof(struct node));
        printf("\n Enter the data:");
        scanf("%d", &y->data);
        x->next = y;
        y->next = head;
        x = y;
        printf("\n If you wish to continue press 1 otherwise 0:");
        scanf("%d", &c);
    }
}

/*Function to insert an element at the begining of the list*/

void ins_at_beg()
{
    x = head;
    y = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter the data:");
    scanf("%d", &y->data);
    while (x->next != head)
    {
        x = x->next;
    }
    x->next = y;
    y->next = head;
    head = y;
}

/*Function to insert an element at any position the list*/

void ins_at_pos()
{
    struct node *ptr;
    int c = 1, pos, count = 1;

    y = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("cannot enter an element at this place");
    }
    printf("\n Enter the data:");
    scanf("%d", &y->data);
    printf("\n Enter the position to be inserted:");
    scanf("%d", &pos);
    x = head;
    ptr = head;
    while (ptr->next != head)
    {
        count++;
        ptr = ptr->next;
    }
    count++;
    if (pos > count)
    {
        printf("OUT OF BOUND");
        return;
    }
    while (c < pos)
    {
        z = x;
        x = x->next;
        c++;
    }
    y->next = x;
    z->next = y;
}

/*Function to delete an element at any begining of the list*/

void del_at_beg()
{
    if (head == NULL)
        printf("\n List is empty");
    else
    {
        x = head;
        y = head;
        while (x->next != head)
        {
            x = x->next;
        }
        head = y->next;
        x->next = head;
        free(y);
    }
}

/*Function to delete an element at any position the list*/

void del_at_pos()
{
    if (head == NULL)
        printf("\n List is empty");
    else
    {
        int c = 1, pos;
        printf("\n Enter the position to be deleted:");
        scanf("%d", &pos);
        x = head;
        while (c < pos)
        {
            y = x;
            x = x->next;
            c++;
        }
        y->next = x->next;
        free(x);
    }
}

/*Function to display the elements in the list*/

void print()
{
    if (head == NULL)
        printf("\n List is empty");
    else
    {
        x = head;
        while (x->next != head)
        {
            printf("%d->", x->data);
            x = x->next;
        }
        printf("%d", x->data);
    }
}

/*Function to search an element in the list*/

void search()
{
    int search_val, count = 0, flag = 0;
    printf("\nenter the element to search\n");
    scanf("%d", &search_val);
    if (head == NULL)
        printf("\nList is empty nothing to search");
    else
    {
        x = head;
        while (x->next != head)
        {
            if (x->data == search_val)
            {
                printf("\nthe element is found at %d", count);
                flag = 1;
                break;
            }
            count++;
            x = x->next;
        }
        if (x->data == search_val)
        {
            printf("element found at postion %d", count);
        }
        if (flag == 0)
        {
            printf("\nelement not found");
        }
    }
}

/*Function to sort the list in ascending order*/

void sort()
{
    struct node *ptr, *nxt;
    int temp;

    if (head == NULL)
    {
        printf("empty nextedlist");
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            nxt = ptr->next;
            while (nxt != head)
            {
                if (nxt != head)
                {
                    if (ptr->data > nxt->data)
                    {
                        temp = ptr->data;
                        ptr->data = nxt->data;
                        nxt->data = temp;
                    }
                }
                else
                {
                    break;
                }
                nxt = nxt->next;
            }
            ptr = ptr->next;
        }
    }
}

/*Function to update an element at any position the list*/
/*void update()
{
    struct node *ptr;
    int search_val;
    int replace_val;
    int flag = 0;

    if (head == NULL)
    {
        printf("\n empty list");
    }
    else
    {
        printf("enter the value to be edited\n");
        scanf("%d", &search_val);
        fflush(stdin);
        printf("enter the value to be replace\n");
        scanf("%d", &replace_val);
        ptr = head;
        while (ptr->next != head)
        {
            if (ptr->data == search_val)
            {
                ptr->data = replace_val;
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }
        if (ptr->data == search_val)
        {
            ptr->data = replace_val;
            flag = 1;
        }
        if (flag == 1)
        {
            printf("\nUPdate sucessful");
        }
        else
        {
            printf("\n update not successful");
        }
    }
}*/

/*Function to display the elements of the list in reverse order*/

void reverse(struct node *p)
{
    int i = 0;

    if (head == NULL)
    {
        printf("empty nexted list");
    }
    else
    {
        if (p->next != head)
        {
            i = p->data;
            reverse(p->next);
            printf(" %d", i);
        }
        if (p->next == head)
        {
            printf(" %d", p->data);
        }
    }
}
void ins_at_end(){
    int data;

    
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    
    printf("\nEnter data to be inserted : \n");
    scanf("%d", &data);

    
    if (head == NULL)
    {
        temp->data = data;
        temp->next = temp;
        head = temp;
    }

    
    else
    {
        temp->data = data;
        temp->next = head->next;
        head->next = temp;
        head = temp;
    }
}
void del_at_end(){
    int data;

    
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    
    printf("\nEnter data to be inserted : \n");
    scanf("%d", &data);

    
    if (head == NULL)
    {
        temp->data = data;
        temp->next = temp;
        head = temp;
    }

    
    else
    {
        temp->data = data;
        temp->next = head->next;
        head->next = temp;
        head = temp;
    }

}
