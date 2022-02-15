#include <iostream>
#include "Typedefs.h"
using namespace std;

Node* BST_SearchItem(Node* root, int item)
{
	if (root == NULL || root->value == item)
		return root;

	if (item < root->value)
		return BST_SearchItem(root->leftNode, item);
	else
		return BST_SearchItem(root->rightNode, item);
}

Node* BST_InsertItem(Node* root, int item)
{
	if (root == NULL)
		return CreateNode(item);

	if (item < root->value)
		root->leftNode = BST_InsertItem(root->leftNode, item);
	else
		root->rightNode = BST_InsertItem(root->rightNode, item);

	return root;
}

Node* BST_GetMinValueNode(Node* node)
{
	Node* current = node;
	while (current && current->leftNode != NULL)
		current = current->leftNode;
	return current;
}

Node* BST_GetMaxValueNode(Node* node)
{
	Node* current = node;
	while (current && current->rightNode != NULL)
		current = current->rightNode;
	return current;
}

Node* BST_RemoveItem(Node* root, int item)
{
	if (root == NULL)
		return NULL;

	if (item < root->value)
	{
		root->leftNode = BST_RemoveItem(root->leftNode, item);
	}
	else if (item > root->value)
	{
		root->rightNode = BST_RemoveItem(root->rightNode, item);
	}
	else // reached to equal node
	{
		if (root->leftNode == NULL)
		{
			Node* node = root->rightNode;
			delete root;
			return node;
		}
		else if (root->rightNode == NULL)
		{
			Node* node = root->leftNode;
			delete root;
			return node;
		}

		// node has two children replace it with inorder successor
		Node* node = BST_GetMinValueNode(root->rightNode);
		root->value = node->value;
		root->rightNode = BST_RemoveItem(root->rightNode, node->value);
	}

	return root;
}

void BinarySearchTreeUsageExample()
{
	printf("\n\n05. BinarySearchTreeUsageExample: ");

	int itemList[] = { 5, 2, 8, 18, 12 };

	Node* root = NULL;
	printf("\nInsert items: ");
	for (int i = 0; i < sizeof(itemList) / sizeof(itemList[0]); i++)
	{
		printf("%d ", itemList[i]);
		if (root == NULL)
		{
			root = BST_InsertItem(NULL, itemList[0]);
			continue;
		}

		BST_InsertItem(root, itemList[i]);
	}

	printf("\nInOrder  : ");
	Tree_TraverseInorder(root);

	printf("\nPreOrder : ");
	Tree_TraversePreorder(root);

	printf("\nPostOrder: ");
	Tree_TraversePostorder(root);

	Node* min = BST_GetMinValueNode(root);
	printf("\nMinimum value BST: %d", min->value);

	Node* max = BST_GetMaxValueNode(root);
	printf("\nMaximum value BST: %d", max->value);

	Node* node = BST_SearchItem(root, 18);
	if (node)
		printf("\nBST Item found: %d", node->value);
	else
		printf("\nBST Item not found");
}