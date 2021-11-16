#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void disp();
int len();
int size=0;
void topnode();
struct node
{
    int data;
    struct node *link;
};

struct node *root=NULL;
struct node *top=NULL;

int main()
{
    char c;
    printf("\n*********Stack using Linked list*******\n");
    printf("Do you want to specify the size of the stack, y/n ");
    scanf("%c", &c);
    if(c=='y')
    {
        printf("enter size of stack: ");
        scanf("%d", &size);
    }
    if(c=='n')
    {
        size=9999;
    }
    int ch;
    while(1)
    {
        printf("1 for Push\n");
        printf("2 for Pop\n");
        printf("3 for Display\n");
        printf("4 for Top element\n");
        printf("5 for Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        system("clear");
        switch(ch)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: disp();
                    break;
            case 4: topnode();
                    break;
            case 5: exit(1);
            default: printf("Invalid input");
        }
    }
}

void topnode()
{
    if(root==NULL)
        printf("Underflow\n");
    else
    {
        struct node *p=root;
        while(p->link)
            p=p->link;
        printf("top element: %d\n", p->data);
    }
}

void pop()
{
    if(root==NULL)
        printf("Underflow\n");
    else
    {
        if(len()==1)
        {
            printf("%d is successfully popped\n", top->data);
            root=top=NULL;
        }
        else
        {
            struct node *p=root;
            while(p->link!=top)
                p=p->link;
            top=p;
            p=p->link;
            top->link=NULL;
            printf("%d is successfully popped\n", p->data);
            free(p);
        }
    }
}

void disp()
{
    if(root==NULL)
        printf("underflow");
    else
    {
        struct node *p=root;
        while(p)
        {
            printf("%d\t", p->data);
            p=p->link;
        }
        printf("\n");
    }
}

int len()
{
    struct node *p=root;
    if(p==NULL){
        return 0;
        }
    else
    {
        int c=0;
        while(p){
         c++;
         p=p->link;
        }
        return c;
    }
}

void push()
{
    if(len()==size)
        printf("Overflow\n");
    else
    {
        struct node *temp;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&temp->data);
        temp->link= NULL;
        if(root==NULL)
        {
            root=temp;
            top=temp;
        }
        else
        {
            struct node *p;
            top->link=temp;
            top=temp;
        }
        printf("%d is successfully pushed.\n",temp->data);
    }
}
