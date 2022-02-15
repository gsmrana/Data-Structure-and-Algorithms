#ifndef TYPEDEFS__H
#define TYPEDEFS__H

#include <stdint.h>

typedef struct item_node Node;

struct item_node
{
	int value;
	Node* leftNode;
	Node* rightNode;
};


void StackUsageExample();
void QueueUsageExample();
void LinkedListUsageExample();
void BinaryTreeUsageExample();
void BinarySearchTreeUsageExample();
void AvlTreeUsageExample();
void PrefixPostfixUsageExample();
void SearchingAlgosUsageExample();
void SortingAlgosUsageExample();

Node* CreateNode(int item);
void Tree_TraverseInorder(Node* root);
void Tree_TraversePreorder(Node* root);
void Tree_TraversePostorder(Node* root);

Node* BST_SearchItem(Node* root, int item);
Node* BST_InsertItem(Node* root, int item);
Node* BST_RemoveItem(Node* root, int item);

Node* AvlTree_SearchItem(Node* root, int item);
Node* AvlTree_InsertItem(Node* root, int item);
bool AvlTree_RemoveItem(Node* root, int item);

#endif //TYPEDEFS__H