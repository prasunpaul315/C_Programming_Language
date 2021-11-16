#include <stdio.h>
#include<stdlib.h>
#define SIZE 5
int stack [SIZE],top=-1;

void traverse();
void push(int);
int pop();
int isEmpty();
int isFull();
void peek();
void findMin();
int main()
{
    int ch,item;
    while(1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Traverse\n");
        printf("5. Retrieving Min\n");
        printf("6. Quit\n");
        printf("\n*********************\n");
        printf("Enter Your Choice :");
        scanf("%d",&ch);
        system("clear");
        switch(ch)
        {
        case 1: printf("Enter Element :");
                scanf("%d",&item);
                push(item);
                break;
        case 2: item=pop();
                if(item==0)
                {
                    printf("Stack is underflow.\n");
                }
                else
                {
                    printf("Pop Element is : %d\n",item);
                }
                break;
        case 3: peek();
                break;
        case 4: traverse();
                break;
        case 5: findMin();
                break;
        case 6: exit(1);
        default: printf("Invalid Input\n");
        }
    }
}

void findMin()
{
    if(top==-1)
        printf("underflow\n");
    else
    {
        int min=stack[0];
        for(int i=0;i<=top;i++)
        {
            if(stack[i]<min)
                min=stack[i];
        }
        printf("Min element: %d\n", min);
    }
}




void push(int ele)
{
    if(isFull())
    {
        printf("Stack is Overflow.\n");
    }
    else
    {
      //  top++;
        stack[++top]=ele;
        printf("%d is Inserted.\n",ele);
    }
}
int isFull()
{
    if(top==SIZE-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int pop()
{
    if(isEmpty())
    {
        return 0;
    }
    else
    {
        return stack[top--];
    }
}
int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void traverse()
{
    int i;
    if(isEmpty())
    {
        printf("No Elements in the Stack.\n");
    }
    else
    {
        printf("Stack Elements are :\n");
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
        printf("\n");
    }
}

void peek()
{
    if(isEmpty())
    {
        printf("Stack is Empty.\n");
    }
    else{
        printf("Peek Element is : %d.\n",stack[top]);
    }
}

