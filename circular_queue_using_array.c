#include <stdio.h>
#include <stdlib.h>
#define MAX 4

void enqueue();
void dequeue();
void disp();
//int len();
int queue[MAX];
int front=-1;
int rear=-1;
int main()
{
    int ch;
    while(1)
    {
        printf("\n*********Circular Queue Operation using Array*******\n");
        printf("1 for Enqueue\n");
        printf("2 for Dequeue\n");
        printf("3 for Display\n");
        printf("4 for Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        system("cls");
        switch(ch)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: disp();
                    break;
            case 4: exit(1);
            default: printf("Invalid input");
        }
    }
}

void enqueue()
{
    if((rear+1)%MAX == front)
        printf("Overflow");
    else if(front==-1 && rear==-1)
    {
        int n;
        printf("Enter element: ");
        scanf("%d", &n);
        front=rear=0;
        queue[rear]=n;
        printf("%d is successfully enqueued.", n);
    }
    else
    {
        int n;
        printf("Enter element: ");
        scanf("%d", &n);
        rear=(rear+1)%MAX;
        queue[rear]=n;
        printf("%d is successfully enqueued.", n);
    }
}

void dequeue()
{
    if(front==-1 && rear==-1)
        printf("underflow");
    else if(front==rear)
    {
        printf("dequeueing %d",queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("dequeueing %d",queue[front]);
        front=(front+1)%MAX;
    }
}
void disp()
{
    if(front==-1 && rear==-1)
        printf("empty queue");
        else
        {
            int i=front;
            while(i!=rear)
            {
                printf("%d\t", queue[i]);
                i=(i+1)%MAX;
            }
        printf("%d\t", queue[i]);
        }
}








