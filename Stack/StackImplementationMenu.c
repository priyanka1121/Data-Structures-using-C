//min and max are not done


#include <stdio.h>
int stack[50],choice,n,top=-1,i;
void push();
void pop();
void display();
void peek();
void count();
void search();
void max();
int main()
{
    
    printf("\n Enter the size of stack:");
    scanf("%d",&n);
    printf("\nEnter your choice");
    printf("\n 1.Push\n 2.pop\n 3.Display\n 4.Peek\n 5.Count\n6.Search\n7.Find Max\n8.Exit");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                peek();
                break;
            }
            case 5:
            {
                count();
                break;
            }
            case 6:
            {
                search();
                break;
            }
            case 7:
            {
                max();
                break;
            }
            default:
            {
                printf ("\nInvalid choice!!!");
            }
                
        }
    }
    while(choice!=4);
    return 0;
}
void push(){
    int x;
    printf("Enter data: ");
    scanf("%d",&x);
    top++;
    stack[top]=x;
}
void pop(){
    //int i;
    i= stack[top];
    top--;
    printf("Deleted item is %d",i);
}
void display(){
    for(i=top;i>=0;i--){
        printf("Data is %d\n",stack[i]);
        
    }
}
void peek(){
    printf("TopMost element is %d",stack[top]);
}
void count(){
    printf("No. of elements are: %d",(top+1));
    }
void search(){
    int key;
    printf("Enter the element you want to search: ");
    scanf("%d",&key);
    for(i = top; i >=0; i--)
    {
        if(stack[i] == key)
        {
           printf("Item found at %d",i);
           break;
        }
        else if(i==0){
            printf("Item not found!!");
        }
    }
}
void max(){
    
}

