#include <stdio.h>
#include <stdlib.h>


void enqueue();
void dequeue();
void disp();
int len();
int size=0;
struct node
{
    int data;
    struct node *link;
};

struct node *front=NULL;
struct node *rear=NULL;

int main()
{
    char c;
    printf("Do you want to specify the size of the queue, y/n ");
    scanf("%c", &c);
    if(c=='y')
    {
        printf("enter size of queue: ");
        scanf("%d", &size);
    }
    if(c=='n')
    {
        size=9999;
    }
        int ch;
        while(1)
        {
            printf("\n*********Circular Queue Operation using Circular Linked list*******\n");
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

void dequeue()
{
    if(front==NULL)
    {
        printf("Underflow");
    }
    else
    {
        struct node *p;
        p=front;
        front=front->link;
        rear->link=front;
        printf("%d is successfully dequeued", p->data);
        p->link=NULL;
        free(p);
    }
}

void disp()
{
    struct node *p=front;
    if(p==NULL)
    {
        printf("Empty queue");
    }
    else
    {
        while(p->link!=front)
        {
            printf("%d\t", p->data);
            p=p->link;
        }
        printf("%d\t", p->data);
    }
}

int len()
{
    int c=0;
    struct node *p;
    p=front;
    if(p==NULL)
        return 0;
    else
    {
        while(p->link!=front)
        {
            c++;
            p=p->link;
        }
        c++;
        return c;
    }
}

void enqueue()
{

    if(len()==size)
        printf("Overflow");
    else
    {
        struct node *temp;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &temp->data);
        if(front==NULL)
        {
            front=temp;
            rear=temp;
            temp->link=temp;
        }
        else
        {
            rear->link=temp;
            rear=temp;
            temp->link=front;
        }
        printf("%d is successfully inserted into queue", temp->data);
    }


}












