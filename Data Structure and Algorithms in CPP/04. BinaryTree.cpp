#include <iostream>
#include "Typedefs.h"
using namespace std;

Node* CreateNode(int item)
{
	Node* node = new Node();
	node->value = item;
	node->leftNode = NULL;
	node->rightNode = NULL;
	return node;
}

Node* AddLeftNode(Node* root, int item)
{
	if (root == NULL)
		return NULL;

	root->leftNode = CreateNode(item);
	return root->leftNode;
}

Node* AddRightNode(Node* root, int item)
{
	if (root == NULL)
		return NULL;

	root->rightNode = CreateNode(item);
	return root->rightNode;
}

/*
*		  _ 1 _
*		/		\
*	   2	     3
*	 /   \	   /   \
*   4	  5	  6	    7
*
*/
Node* CreateTree1()
{
	Node* root = CreateNode(1);
	Node* two = AddLeftNode(root, 2);
	Node* three = AddRightNode(root, 3);

	AddLeftNode(two, 4);
	AddRightNode(two, 5);

	AddLeftNode(three, 6);
	AddRightNode(three, 7);

	return root;
}

/*
*		  _ 2 _
*		/		\
*	   7	     9
*	 /   \		  \
*   1	  6		   8
*	    /   \	 /   \
*	   5    10  3	  4
*
*/
Node* CreateTree2()
{
	Node* root = CreateNode(2);
	Node* seven = AddLeftNode(root, 7);
	Node* nine = AddRightNode(root, 9);

	Node* one = AddLeftNode(seven, 1);
	Node* six = AddRightNode(seven, 6);

	Node* five = AddLeftNode(six, 5);
	Node* ten = AddRightNode(six, 10);

	Node* eight = AddRightNode(nine, 8);
	Node* three = AddLeftNode(eight, 3);
	Node* four = AddRightNode(eight, 4);

	return root;
}

void Tree_ConsoleView(Node* root)
{
	if (root == NULL)
		return;

	printf("\t_ %d _ ", root->value);
	printf("\n   /\t\t\\");
	printf("\n  %d ", root->leftNode->value);
	printf("\t\t%d ", root->rightNode->value);
}

// InOrder: LEFT, ROOT, RIGHT
void Tree_TraverseInorder(Node* root)
{
	if (root == NULL)
		return;

	Tree_TraverseInorder(root->leftNode);
	printf("%d ", root->value);
	Tree_TraverseInorder(root->rightNode);
}

// PreOrder: ROOT, LEFT, RIGHT
void Tree_TraversePreorder(Node* root)
{
	if (root == NULL)
		return;

	printf("%d ", root->value);
	Tree_TraversePreorder(root->leftNode);
	Tree_TraversePreorder(root->rightNode);
}

// PostOrder: LEFT, RIGHT, ROOT
void Tree_TraversePostorder(Node* root)
{
	if (root == NULL)
		return;

	Tree_TraversePostorder(root->leftNode);
	Tree_TraversePostorder(root->rightNode);
	printf("%d ", root->value);
}

void BinaryTreeUsageExample()
{
	printf("\n\n04. BinaryTreeUsageExample: ");

	Node* root = CreateTree2();
	printf("\nTree_ConsoleView: \n");
	Tree_ConsoleView(root);

	printf("\nInOrder  : ");
	Tree_TraverseInorder(root);

	printf("\nPreOrder : ");
	Tree_TraversePreorder(root);

	printf("\nPostOrder: ");
	Tree_TraversePostorder(root);
}