#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};
int len;
struct node *root=NULL;

void createnode();
void createlist();
int length();
void disp();
void addatafter();
void delfirstnode();
void dellastnode();
void addatbef();

main()
{
	int ch;
	while(1)
	{
		printf("\n*****DOUBLE LINKED-LIST OPERATION*****\n");
		printf("1. Create a Single node or inserted at the End\n");
		printf("2. Create a list of nodes\n");
		printf("3. Display of list\n");
		printf("4. length of list\n");
		printf("5. Insert a new node at after\n");
		printf("6. Insert a new node at before\n");
		printf("7. Delete first node\n");
		printf("8. Delete last node\n");
		printf("9. Exit\n");
		printf("\n*************************************\n");
		printf("\nEnter your Choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: createnode();
					break;
			case 2: createlist();
					break;
			case 3: disp();
					break;
			case 4: len=length();
                    printf("Length is %d\n",len);
					break;
			case 5: addatafter();
					break;
			case 6: addatbef();
					break;
			case 7: delfirstnode();
                    break;
            case 8: dellastnode();
                    break;
			case 9: exit(1);
			default: printf("Invalid Input\n");
		}
	}
}


void addatbef()
{
    int val;
    struct node *p, *q, *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Node data : ");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;
    printf("Enter node value that before to be insert :");
    scanf("%d",&val);
    p=root;
    if(p->data==val)
    {
        p->left=temp;
        temp->right=p;
        root=temp;
    }
    else
    {
        while(p->data!=val)
        {
            q=p;
            p=p->right;
        }
        temp->right=p;
        p->left=temp;
        temp->left=q;
        q->right=temp;
    }
    printf("%d is successfully inserted.\n",temp->data);
}


void dellastnode()
{
    struct node *p;
    if(root==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        p=root;
        while(p->right!=NULL)
        {
            p=p->right;
        }
        printf("%d id deleted\n",p->data);
        p->left->right=p->right;
        p->left=NULL;
        free(p);
    }
}


void delfirstnode()
{
    struct node *p;
    if(root==NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        p=root;
        root=root->right;
        root->left=NULL;
        printf("%d is deleted.",p->data);
        free(p);
    }
}


void addatafter()
{
    int val,i=1;
    len=length();
    struct node *temp, *p, *q;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to be insert :");
    scanf("%d",&temp->data);
    temp->right=NULL;
    temp->left=NULL;
    printf("Enter node value that after to be insert :");
    scanf("%d",&val);
    p=root;
    while(p->data!=val)
    {
    p=p->right;
     i++;
    }
    if(p->right==NULL)
    {
        q=p;
        q->right=temp;
        temp->left=q;
    }
    else
    {
        temp->right=p->right;
        p->right->left=temp;
        temp->left=p;
        p->right=temp;
    }
    printf("%d is successfully inserted.\n",temp->data);
}


void createlist()
{
    int num,i;
    printf("How many node do u want to create ?");
    scanf("%d",&num);
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    root=temp;
    printf("Enter node data  for node no 1: ");
    scanf("%d",&temp->data);

    temp->left=NULL;
    temp->right=NULL;
    printf("%d is successfully inserted\n",temp->data);
    for(i=2;i<=num;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter node data for node no %d: ",i);
		scanf("%d",&temp->data);
		temp->left =NULL;
		temp->right =NULL;
		if(root==NULL)
		{
			root=temp;
		}
		else
		{
		struct node *p;
		p=root;
		while(p->right!=NULL)
		{
			p=p->right;
		}
		p->right =temp;
		temp->left =p;
		}
		printf("%d is successfully inserted\n",temp->data);
    }
    printf("\nAll node datas are successfully inserted.\n");

}


void createnode()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node value :");
	scanf("%d",&temp->data);
	temp->left =NULL;
	temp->right =NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
	struct node *p;
	p=root;
	while(p->right!=NULL)
	{
		p=p->right;
	}
	p->right =temp;
	temp->left =p;
    }
    printf("%d is successfully inserted \n",temp->data);
}


int length()
{
	struct node* temp;
	temp=root;
	int count;
	if(root==NULL)
    {
        count=0;
    }
    else
    {
    count=1;
	while(temp->right!=NULL)
	{
	    count++;
        temp=temp->right ;
	}
    }
	return count;
}


void disp()
{
	struct node* temp;
	temp=root;
	if(temp==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while(temp!=NULL)
		{
        printf("%d-->\t",temp->data );
        temp=temp->right ;
		}
	}
}
