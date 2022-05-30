#ifndef COMMONLIBS__H
#define COMMONLIBS__H

#include <stdint.h>
#include "Typedefs.h"

/* Modules usage demonstaion API */
void StackUsageExample();
void QueueUsageExample();
void LinkedListUsageExample();
void BinaryTreeUsageExample();
void BinarySearchTreeUsageExample();
void AvlTreeUsageExample();
void PrefixPostfixUsageExample();
void SearchingAlgosUsageExample();
void SortingAlgosUsageExample();
void PatternMatchingAlgosUsageExample();

/* Tree module API */
Node* CreateNode(int item);
void Tree_TraverseInorder(Node* root);
void Tree_TraversePreorder(Node* root);
void Tree_TraversePostorder(Node* root);

/* Binary Search Tree API */
Node* BST_SearchItem(Node* root, int item);
Node* BST_InsertItem(Node* root, int item);
Node* BST_RemoveItem(Node* root, int item);

/* AVL Tree API */
Node* AvlTree_SearchItem(Node* root, int item);
Node* AvlTree_InsertItem(Node* root, int item);
bool AvlTree_RemoveItem(Node* root, int item);

/* Common library API */
void display_array(int* buf, int length);


#endif //COMMONLIBS__H