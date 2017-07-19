#include <stdio.h>
#include <stdlib.h>

/*
�嫬��binay search tree���غc���D(�Q��linked list�갵)
�̫�Q��preorder traversal�L�Xbinary tree
*/

typedef struct NODE
{
	int value;
	struct NODE*left;
	struct NODE*right;
}Node;

Node* insert(Node*,int value);
void delete_tree(Node*);
void preorder(Node*);

int main()
{
	int n;
	int i,j,k;
	int input;
	Node*head=NULL;
	while(scanf("%d",&n)!=EOF)
	{
		head = NULL;
		for(i=0;i<n;i++)
		{
			scanf("%d",&input);
			head = insert(head,input);
		}
		preorder(head);
		printf("\n");
		delete_tree(head);
	}
	return 0;
}

Node* insert(Node*head,int value)
{
	Node*node,*current;
	node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	if(head==NULL)
	{
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	else
	{
		current = head;
		while(1)
		{
			if(value > current->value)
			{
				if(current->right == NULL)
				{
					current->right = node;
					break;
				}
				else
					current = current->right;	
			}
			else
			{
				if(current->left == NULL)
				{
					current->left = node;
					break;
				}
				else
					current = current->left;
			}
		}
		return head;
			
	}
}

void delete_tree(Node*head)
{
	if(head!=NULL)
	{
		delete_tree(head->left);
		delete_tree(head->right);
		free(head);
	}
}

void preorder(Node*head)
{
	if(head!=NULL)
	{
		printf("%d ",head->value);
		preorder(head->left);
		preorder(head->right);
	}
}







