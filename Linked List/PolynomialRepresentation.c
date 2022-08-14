#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int pow;
    struct node *next;
};
void createPoly(struct node **head, struct node **tail, int c, int p)
{
    if (!(*head))
    {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->coeff = c;
        newnode->pow = p;
        newnode->next = NULL;
        (*head) = newnode;
        (*tail) = newnode;
    }
    else
    {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->coeff = c;
        newnode->pow = p;
        (*tail)->next = newnode;
        (*tail) = newnode;
        newnode->next = NULL;
    }
}
void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%dx^%d", head->coeff, head->pow);

        if (head->coeff >= 0 && head->next != NULL)
        {
            printf("+");
        }
        head = head->next;
    }
}
int main()
{
    struct node *head = NULL;
    struct node *tail = NULL;
    createPoly(&head, &tail, 10, 3);
    createPoly(&head, &tail, 6, 2);
    createPoly(&head, &tail, 5, 0);
    createPoly(&head, &tail, 8, 0);
    display(head);
}
