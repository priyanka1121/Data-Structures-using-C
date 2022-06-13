#include<stdio.h>
#include<stdlib.h>

void insert();
void delete();
void display();
int arr[50],n;
int rear, front = -1;

void main()
{
    int choice;
    while(1)
    {
        printf("1. Insert the element \n");
        printf("2. Delete the element \n");
        printf("3. Display all the elements \n");
        printf("4. Quit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insert(1); 
                break;

            case 2:
                delete();
                break;

            case 3:
                display ();
                break;

            case 4:
                exit(1);

            default:
                printf ("Wrong choice!! \n");
        }
    }
}