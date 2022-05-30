#include <iostream>
#include "Typedefs.h"
#include "CommonLibs.h"
using namespace std;

typedef enum avl_unbalance_type
{
	UNBALANCE_NONE,
	UNBALANCE_LEFT,
	UNBALANCE_RIGHT,
	UNBALANCE_LEFT_RIGHT,
	UNBALANCE_RIGHT_LEFT,
} UnbalanceType;

void AvlTree_LeftRotation(Node* root)
{
	Node* topNode = root;
	Node* middleNode = root->rightNode;
	middleNode->leftNode = topNode;
}

void AvlTree_RightRotation(Node* root)
{
	Node* topNode = root;
	Node* middleNode = root->leftNode;
	middleNode->rightNode = topNode;
}

void AvlTree_LeftRightRotation(Node* root)
{
	AvlTree_LeftRotation(root->leftNode);
	AvlTree_RightRotation(root);
}

void AvlTree_RightLeftRotation(Node* root)
{
	AvlTree_RightRotation(root->rightNode);
	AvlTree_LeftRotation(root);
}

int AvlTree_GetBalacedFactor(Node* root)
{
	if (root == NULL)
		return 0;

	int maxLeftNodeCount = 0;
	int maxRightNodeCount = 0;

	Node* node = root->leftNode;
	// ToDo: find max from all
	while (node != NULL)
	{
		maxLeftNodeCount++;
		node = node->leftNode;
	}

	node = root->rightNode;
	// ToDo: find max from all
	while (node != NULL)
	{
		maxRightNodeCount++;
		node = node->rightNode;
	}

	return maxLeftNodeCount - maxRightNodeCount;
}

UnbalanceType AvlTree_GetUnbalanceType(Node* root)
{
	int balanceFactor = AvlTree_GetBalacedFactor(root);
	// ToDo: detect unbalance type
	return UNBALANCE_NONE;
}

void AvlTree_MaintainHeightBalance(Node* root)
{
	if (root == NULL)
		return;

	UnbalanceType unbalanceType = AvlTree_GetUnbalanceType(root);
	switch (unbalanceType)
	{
	case UNBALANCE_LEFT:
		AvlTree_RightRotation(root);
		break;
	case UNBALANCE_RIGHT:
		AvlTree_LeftRotation(root);
		break;
	case UNBALANCE_LEFT_RIGHT:
		AvlTree_LeftRightRotation(root);
		break;
	case UNBALANCE_RIGHT_LEFT:
		AvlTree_RightLeftRotation(root);
		break;
	}

	AvlTree_MaintainHeightBalance(root->leftNode);
	AvlTree_MaintainHeightBalance(root->rightNode);
}

Node* AvlTree_SearchItem(Node* root, int item)
{
	return BST_SearchItem(root, item);
}

Node* AvlTree_InsertItem(Node* root, int item)
{
	Node* node = BST_InsertItem(root, item);
	AvlTree_MaintainHeightBalance(root);
	return node;
}

bool AvlTree_RemoveItem(Node* root, int item)
{
	BST_RemoveItem(root, item);
	AvlTree_MaintainHeightBalance(root);
	return true;
}

void AvlTreeUsageExample()
{
	printf("\n\n06. AvlTreeUsageExample: ");

	int itemList[] = { 2, 5, 8, 12, 18 };
	//int itemList[] = { 18, 12, 8, 5, 2 };

	Node* root = NULL;
	printf("\nInsert items: ");	
	for (int i = 0; i < sizeof(itemList) / sizeof(itemList[0]); i++)
	{
		printf("%d ", itemList[i]);
		if (root == NULL)
		{
			root = AvlTree_InsertItem(NULL, itemList[0]);
			continue;
		}

		AvlTree_InsertItem(root, itemList[i]);
	}

	printf("\nInOrder  : ");
	Tree_TraverseInorder(root);

	printf("\nPreOrder : ");
	Tree_TraversePreorder(root);

	printf("\nPostOrder: ");
	Tree_TraversePostorder(root);
}