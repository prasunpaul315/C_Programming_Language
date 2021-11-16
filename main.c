#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *link;
};
struct node *root=NULL;
int len;
void append();
void disp();
int length();
void reverse_list();

void del();
void del_with_location();
void del_with_nodeData();

void add_at_before();
void add_at_before_with_nodeData();
void add_at_before_with_location();

void add_at_after();
void add_at_after_with_nodeData();
void add_at_after_with_location();

main()
{
    int ch;
    while(1)
    {
        printf("\n******SINGLE LINKED-LIST OPERATION******\n");
        printf("1. Append\n");
        printf("2. Display\n");
        printf("3. Length of the list\n");
        printf("4. Add a New node at Before\n");
        printf("5. Add a New node at After\n");
        printf("6. Reverse list\n");
        printf("7. Delete\n");
        printf("8. Exit\n");
        printf("****************************\n\n");
        printf("Enter your option :");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: append();
                    break;
            case 2: disp();
                    break;
            case 3: len=length();
                    printf("Length is : %d\n",len);
                    break;
            case 4: add_at_before();
                    break;
            case 5: add_at_after();
                    break;
            case 6: printf("Original list is : ");
                    disp();
                    printf("Reverse form is  : ");
                    reverse_list();
                    disp();
                    reverse_list();
                    break;
            case 7: del();
                    break;
            case 8: exit(1);
            default: printf("Invalid Input.\n");
        }
    }
}

void append()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter node data: ");
    scanf("%d",&temp->data);
    temp->link= NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node *p;
        p=root;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
    printf("%d is successfully Inserted.\n",temp->data);
}

void disp()
{
    struct node *temp;
    temp=root;
    if(root==NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->link;
        }
    }printf("\n");
}

void reverse_list()
{
    int i,j,k;
    struct node *p ,*q, *temp;
    int len=length();
    i=0;j=len-1;
    p=q=root;
    while(i<j)
    {
        k=0;
        while(k<j)
        {
            q=q->link;
            k++;
        }
        temp=p->data;
        p->data=q->data;
        q->data=temp;
        i++;j--;
        p=p->link;
        q=root;
    }
}

int length()
{
    struct node *temp;
    temp=root;
    int c=0;
    while(temp!=NULL)
    {
        c++;
        temp=temp->link;
    }
    return c;
}

void add_at_before_with_nodeData()
{
    struct node *temp, *p, *q, *t;
    int val;
    p=root;
    if(p==NULL)
    {
        printf("Empty List.\n");
    }
    else
    {
        printf("Enter Node Data that before you want to insert a new node : ");
        scanf("%d",&val);
        p=root;
        if(p->data==val)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            printf("Enter node data : ");
            scanf("%d",&temp->data);
            temp->link=root;
            root=temp;
            printf("%d is successfully Inserted.\n",temp->data);
        }
        else
        {
            p=root;
            q=root;
            t=(struct node*)malloc(sizeof(struct node));
            printf("Enter data for newly created node : ");
            scanf("%d",&t->data);
            while(p->data!=val)
            {
                p=p->link;
            }
            while(q->link!=p)
            {
                q=q->link;
            }
            t->link=p;
            q->link=t;
            printf("%d is successfully Inserted.\n",t->data);
        }
    }
}

void add_at_before_with_location()
{
    int loc, i=1;
    int len=length();
    struct node *temp, *p, *q;
    p=root;
    if(p==NULL)
    {
        printf("Empty List.\n");
    }

    else
    {
        printf("Enter location that before a new node to be insert : ");
        scanf("%d",&loc);
        if(loc>len)
        {
            printf("Invalid location.\n");
        }
        else if(loc==1)
        {
            struct node *t;
            t=(struct node*)malloc(sizeof(struct node));
            printf("Enter data for newly created node : ");
            scanf("%d",&t->data);
            t->link=root;
            root=t;
            printf("%d is successfully Inserted.\n",t->data);
        }
        else
        {
            p=root;
            while(i<loc-1)
            {
                p=p->link;
                i++;
            }
            temp=(struct node*)malloc(sizeof(struct node));
            printf("Enter data for newly created node : ");
            scanf("%d",&temp->data);
            temp->link=p->link;
            p->link=temp;
            printf("%d is successfully Inserted.\n",temp->data);
        }
    }
}

void add_at_before()
{
    int ch;
    printf("Enter which way that u want to insert a new node before a given node : \n");
    printf("Press 1 for serial node number.(Starts from 1)\n");
    printf("Press 2 for define particular node data : \n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: add_at_before_with_location();
                break;
        case 2: add_at_before_with_nodeData();
                break;
        default: printf("Invalid input.\n");
    }
}

void del_with_location()
{
    len=length();
    struct node *temp;
    int loc;
    printf("Enter location for delete: ");
    scanf("%d",&loc);
    if(loc>len)
    {
        printf("Invalid Location.");
        printf("Length of list is %d",len);
    }
    else if(loc==1)
    {
        temp=root;
        printf("%d is successfully Deleted.\n",temp->data);
        root=temp->link;
        temp->link=NULL;
        free(temp);
    }
    else
    {
       struct node *p, *q;
       p=q=root;
       int i=1;
       while(i<loc)
       {
           q=p;
           p=p->link;
           i++;
       }
       printf("%d is successfully Deleted.\n",p->data);
       q->link=p->link;
       p->link=NULL;
       free(p);
    }
}

void del_with_nodeData()
{
    struct node *temp,*p;
    int val;
    temp=p=root;
    printf("Enter value you want to delete :");
    scanf("%d",&val);
    if(temp->data==val)
    {
        printf("%d is successfully Deleted.\n",temp->data);
        root=temp->link;
        temp->link=NULL;
        free(temp);
    }
    else
    {
    while(temp->data!=val)
    {
        p=temp;
        temp=temp->link;
    }
    printf("%d is successfully Deleted.\n",temp->data);
    p->link=temp->link;
    temp->link=NULL;
    free(temp);
    }
}

void del()
{
    int ch;
    printf("Enter which way you want to Delete a particular node : \n");
    printf("Press 1 for serial Index number.(Starts from 1)\n");
    printf("Press 2 for define particular node data.\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: del_with_location();
                break;
        case 2: del_with_nodeData();
                break;
        default: printf("Invalid input.\n");
    }
}

void add_at_after_with_location()
{
    struct node *temp, *p;
    int loc, i=1;
    int len=length();
    temp=root;
    if(temp==NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        printf("Enter location that after to be insert : ");
        scanf("%d",&loc);
        if(loc>len)
        {
            printf("Invalid location.\n");
            printf("Length is : %d\n",len);
        }
        else
        {
            p=root;
            while(i<loc)
            {
                p=p->link;
                i++;
            }
            temp=(struct node*)malloc(sizeof(struct node));
            printf("Enter node data : ");
            scanf("%d",&temp->data);
            temp->link=p->link;
            p->link=temp;
            printf("%d is successfully inserted. \n",temp->data);
        }
    }

}

void add_at_after_with_nodeData()
{
    struct node *temp, *p, *q;
    int val;
    p=root;
    if(p==NULL)
    {
        printf("Empty list.\n");
    }
    else
    {
        p=root;
        printf("Enter data that after to be insert a new node : ");
        scanf("%d",&val);
        while(p->data!=val)
        {
            p=p->link;
        }
        q=p;
        if(q->data!=val)
        {
            printf("This node data does not exist.\n");
        }
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter node data : ");
        scanf("%d",&temp->data);
        temp->link=p->link;
        p->link=temp;
        printf("%d is successfully inserted. \n",temp->data);
    }
}

void add_at_after()
{
    int ch;
    printf("Enter which way that u want to insert a new node after a given node : \n");
    printf("Press 1 for serial node number.(Starts from 1)\n");
    printf("Press 2 for define particular node data : \n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: add_at_after_with_location();
                break;
        case 2: add_at_after_with_nodeData();
                break;
        default: printf("Invalid input.\n");
    }
}
