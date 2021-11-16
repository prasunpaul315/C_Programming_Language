#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

bool areIdentical(struct node * root1, struct node *root2)
{
	if (root1 == NULL && root2 == NULL)
		return true;

	if (root1 == NULL || root2 == NULL)
		return false;

	return (root1->data == root2->data &&
			areIdentical(root1->left, root2->left) &&
			areIdentical(root1->right, root2->right) );
}


bool isSubtree(struct node *T, struct node *S)
{
	if (S == NULL)
		return true;

	if (T == NULL)
		return false;

	if (areIdentical(T, S))
		return true;
	return isSubtree(T->left, S) ||
		isSubtree(T->right, S);
}

struct node* newNode(int data)
{
	struct node* node =
		(struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

int main()
{
	struct node *T=newNode(50);
	T->right=newNode(60);
	T->right->right=newNode(66);
	T->left=newNode(30);
	T->left->left= newNode(10);
	T->left->right=newNode(20);
	T->right->left=newNode(20);
	T->left->right->right=newNode(27);

	struct node *S =newNode(30);
	S->right=newNode(20);
	S->left= newNode(10);
	S->right->right = newNode(27);

	if (isSubtree(T, S))
		printf("Tree 2 is subtree of Tree 1");
	else
		printf("Tree 2 is not a subtree of Tree 1");

	getchar();
	return 0;
}






