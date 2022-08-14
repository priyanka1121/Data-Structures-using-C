#include <stdio.h>
#include<stdlib.h>
struct node
{
    int coefficient;
    int power;
    struct node *next;
};
int size = 0;
struct node *head, *tail, *newnode = NULL;
struct node *add(struct node *head1, struct node *head2);
struct node *subtract(struct node *head1, struct node *head2);
struct node *multiply(struct node *head1, struct node *head2);
struct node *getNode(int position);
void insertSorted(int coefficient, int power);
void display();
void insertAtBeginning(int coefficient, int power);
void insertAtLast(int value);
void insertAtPosition(int pos, int value);

void main()
{
    int cofficient, power, choiceForAddingTerms = 1;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    printf("Lets start creating the polynomial....\nVariable will be x , just give us the coefficients and powers.\n");
    printf("Enter the coefficient\n");
    scanf("%d", &cofficient);
    newnode->coefficient = cofficient;
    printf("\nNow enter the power of the variable x which will have the coefficient %d\n", cofficient);
    scanf("%d", &power);
    newnode->power = power;
    head = newnode;
    tail = newnode;
    size++;
    printf("Press 1 -> To add a new term to the polynomial\nPress 2 -> To start performing operations\nPress 3 -> To see the polynomial you have created up until now.\n");
    scanf("%d", &choiceForAddingTerms);
    while (choiceForAddingTerms <= 3)
    {
        if (!(choiceForAddingTerms > 0))
        { // edge case for input.
            printf("Invalid input!");
            return;
        }
        else if (choiceForAddingTerms == 3)
        {
            display();
        }
        else if (choiceForAddingTerms == 2)
        {
            break;
        }
        else if (choiceForAddingTerms == 1)
        {
            printf("Enter the coefficient\n");
            scanf("%d", &cofficient);
            printf("\nNow enter the power of the variable x which will have the coefficient %d\n", cofficient);
            scanf("%d", &power);
            insertSorted(cofficient, power);
        }
        printf("Press 1 -> To add a new term to the polynomial\nPress 2 -> To start performing operations\nPress 3 -> To see the polynomial you have created up until now.\n");
        scanf("%d", &choiceForAddingTerms);
    }
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d -> ", temp->coefficient, temp->power);
        temp = temp->next;
    }
    printf("NULL\nSize of list =  %d \n\n", size);
}

void insertSorted(int coefficient, int power)
{
    struct node *temp = head;
    if (head->next == NULL)
    {
        if (power > head->power)
        {
            insertAtBeginning(coefficient, power);
        }
        else
        {
            while (power < temp->power && temp->next != NULL)
            {
                temp = temp->next;
            }
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->next = NULL;
            newnode->power = power;
            newnode->coefficient = coefficient;
            temp->next = newnode;
            if (temp->next == NULL)
            {
                tail = newnode;
            }
        }
    }
}

void insertAtBeginning(int coefficient, int power)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coefficient = coefficient;
    newnode->power = power;
    newnode->next = head;
    head = newnode;
    size++;
}

struct node *getNode(int location)
{
    struct node *temp = head;
    for (int i = 1; i < location; i++)
    {
        temp = temp->next;
    }
    return temp;
}