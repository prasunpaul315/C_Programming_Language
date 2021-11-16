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
void preOrder(struct node *root);
void postOrder(struct node *root);
void inOrder(struct node *root);


int main()
{
    int num,i,n,j;
    insert(10);insert(15);
    insert(20);insert(25);
    insert(30);insert(47);
    insert(40);insert(42);
    insert(50);insert(70);
    insert(60);insert(54);
   /* printf("How many node you want to insert : ");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("Enter value for node %d : ",i+1);
        scanf("%d",&n);
        insert(n);
    }*/


    printf("\nPre-Order List : \t");
    preOrder(root);
    printf("\nPost-Order List : \t");
    postOrder(root);
    printf("\nIn-Order List : \t");
    inOrder(root);
    printf("\nEnter which node data you want to Delete : ");
    scanf("%d",&j);
    root=del(root,j);
    printf("\nAfter Deleting node %d :",j);
    printf("\nPre-Order List : \t");
    preOrder(root);
    printf("\nPost-Order List : \t");
    postOrder(root);
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

struct node * del(struct node *curr, int val)
{
    if(curr==NULL)
    {
        return NULL;
    }
    else if(val<curr->data)
    {
        curr->left=del(curr->left,val);
    }
    else if(val>curr->data)
    {
        curr->right=del(curr->right,val);
    }
    else
    {
        if(curr->left==NULL && curr->right==NULL)
        {
            curr=NULL;
        }
        else if(curr->left==NULL)
        {
            curr=curr->right;
        }
        else if(curr->right==NULL)
        {
            curr=curr->left;
        }
        else
        {
            struct node *temp;
            temp=findMin(curr->right);
            curr->data=temp->data;
            curr->right=del(curr->right,temp->data);
        }
    }
    return curr;
}

struct node* findMin(struct node* curr)
{
    if(curr->left==NULL)
    {
        return curr;
    }
    return findMin(curr->left);
}

void preOrder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct node *root)
{
    if (root==NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
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
