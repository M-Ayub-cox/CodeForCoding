#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class Node
{
public:

	int data;
	 Node *left;
	Node *right;
    Node *parent;
};
 Node *minValue( Node* node);

 Node * inOrderSuccessor(Node *root,Node *n)
{
// step 1 of the above algorithm
if( n->right != NULL )
	return minValue(n->right);

// step 2 of the above algorithm
 Node *p = n->parent;
while(p != NULL && n == p->right)
{
	n = p;
	p = p->parent;
}
return p;
}

/* Given a non-empty binary search tree, return the minimum data
	value found in that tree. Note that the entire tree does not need
	to be searched. */
 Node *minValue(Node *node) {
Node *current = node;

/* loop down to find the leftmost leaf */
while (current->left != NULL) {
	current = current->left;
}
return current;
}

/* Helper function that allocates a new node with the given data and
	NULL left and right pointers. */
 Node *newNode(int data)
{
 Node *node =new N ode();
node->data = data;
node->left = NULL;
node->right = NULL;
node->parent = NULL;

return(node);
}

/* Give a binary search tree and a number, inserts a new node with
	the given number in the correct place in the tree. Returns the new
	root pointer which the caller should then use (the standard trick to
	avoid using reference parameters). */
 Node *insert( Node *node, int data)
{
/* 1. If the tree is empty, return a new,
	single node */
if (node == NULL)
	return(newNode(data));
else
{
	Node *temp;

	/* 2. Otherwise, recur down the tree */
	if (data <= node->data)
	{
		temp = insert(node->left, data);
		node->left = temp;
		temp->parent= node;
	}
	else
	{
		temp = insert(node->right, data);
		node->right = temp;
		temp->parent = node;
	}

	/* return the (unchanged) node pointer */
	return node;
}
}

/* Driver program to test above functions*/
int main()
{
 Node *root = NULL, *temp, *succ, *min;

//creating the tree given in the above diagram
root = insert(root, 20);
root = insert(root, 8);
root = insert(root, 22);
root = insert(root, 4);
root = insert(root, 12);
root = insert(root, 10);
root = insert(root, 14);
temp = root->left->right->right;

succ = inOrderSuccessor(root, temp);
if(succ != NULL)
	printf("\n Inorder Successor of %d is %d ", temp->data, succ->data);
else
	printf("\n Inorder Successor doesn't exit");

//getchar();
return 0;
}

