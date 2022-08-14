#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    // Define useful field of Node
    int coeff;
    int pow;
    struct Node *next;
} Node;

Node *getNode(int coeff, int pow)
{
    // Create dynamic memory of Node
    Node *ref = (Node *)malloc(sizeof(Node));
    if (ref == NULL)
    {
        // Failed to create memory
        return NULL;
    }
    ref->coeff = coeff;
    ref->pow = pow;
    ref->next = NULL;
    return ref;
}
// Update node value
void updateRecord(Node *ref, int coeff, int pow)
{
    ref->coeff = coeff;
    ref->pow = pow;
}
typedef struct MultiplyPolynomial
{
   
    struct Node *head;
} MultiplyPolynomial;

MultiplyPolynomial *getMultiplyPolynomial()
{
    // Create dynamic memory of MultiplyPolynomial
    MultiplyPolynomial *ref = (MultiplyPolynomial *)
        malloc(sizeof(MultiplyPolynomial));
    if (ref == NULL)
    {
       
        return NULL;
    }
    ref->head = NULL;
    return ref;
}

void insert(MultiplyPolynomial *ref, int coeff, int pow)
{
    if (ref->head == NULL)
    {
       
        ref->head = getNode(coeff, pow);
    }
    else
    {
        Node *node = NULL;
        Node *temp = ref->head;
        Node *loc = NULL;
       
        while (temp != NULL && temp->pow >= pow)
        {
            loc = temp;
            temp = temp->next;
        }
        if (loc != NULL && loc->pow == pow)
        {
            
            loc->coeff = loc->coeff + coeff;
        }
        else
        {
            node = getNode(coeff, pow);
            if (loc == NULL)
            {
               
                node->next = ref->head;
                ref->head = node;
            }
            else
            {
                
                node->next = loc->next;
                loc->next = node;
            }
        }
    }
}

MultiplyPolynomial *multiplyPolynomials(
    MultiplyPolynomial *ref, MultiplyPolynomial *other)
{
    
    MultiplyPolynomial *result = getMultiplyPolynomial();
  
    Node *poly1 = ref->head;
    Node *temp = other->head;
    int pow_value = 0;
    int coefficient = 0;
    
    while (poly1 != NULL)
    {
        temp = other->head;
        while (temp != NULL)
        {
            
            pow_value = poly1->pow + temp->pow;
            coefficient = poly1->coeff * temp->coeff;
            insert(result, coefficient, pow_value);
            // Visit to next node
            temp = temp->next;
        }
        // Visit to next node
        poly1 = poly1->next;
    }
    
    return result;
}

void display(MultiplyPolynomial *ref)
{
    if (ref->head == NULL)
    {
        printf("Empty Polynomial ");
    }
    printf(" ");
    Node *temp = ref->head;
    while (temp != NULL)
    {
        if (temp != ref->head)
        {
            printf(" + %d", temp->coeff);
        }
        else
        {
            printf("%d", temp->coeff);
        }
        if (temp->pow != 0)
        {
            printf("x^%d", temp->pow);
        }
        // Visit to next node
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    MultiplyPolynomial *a = getMultiplyPolynomial();
    MultiplyPolynomial *b = getMultiplyPolynomial();
    // Add node in polynomial A
    insert(a, 9, 3);
    insert(a, 4, 2);
    insert(a, 3, 0);
    insert(a, 7, 1);
    insert(a, 3, 4);
    // Add node in polynomial b
    insert(b, 7, 3);
    insert(b, 4, 0);
    insert(b, 6, 1);
    insert(b, 1, 2);
    
    printf("\n Polynomial A: \n");
    display(a);
    printf(" Polynomial B: \n");
    display(b);
    MultiplyPolynomial *result = multiplyPolynomials(a, b);
    
    printf(" Result\n");
    display(result);
}