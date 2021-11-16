#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;
int val;
struct node * del(struct node *root, int val);
void insert(int value);
struct node *findMin(struct node *root);
void inOrder(struct node *root);


int main()
{
    int num,i,n,j;
    printf("How many node you want to insert : ");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("Enter value for node %d : ",i+1);
        scanf("%d",&n);
        insert(n);
    }
    printf("\nIn-Order List : \t");
    inOrder(root);
    return 0;
}

void insert(int value)
{
    struct node *temp, *parent, *curr;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        curr=root;
        parent=NULL;
        while(1)
        {
            parent=curr;
            if(value<=curr->data)
            {
                curr=curr->left;
                if(curr==NULL)
                {
                    parent->left=temp;
                    return;
                }
            }
            else
            {
                curr=curr->right;
                if(curr==NULL)
                {
                    parent->right=temp;
                    return;
                }
            }
        }
    }
}

void inOrder(struct node *root)
{
    if (root==NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);

}






