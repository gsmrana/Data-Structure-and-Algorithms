#include <iostream>
#include "Typedefs.h"
using namespace std;

class LinkedList
{
private:
	int itemCount;
	Node* firstNode;
	Node* lastNode;

public:
	LinkedList()
	{
		itemCount = 0;
		firstNode = NULL;
		lastNode = NULL;
	}

	void AddItem(int item)
	{
		Node* newnode = new Node();
		newnode->value = item;
		newnode->leftNode = NULL;
		newnode->rightNode = NULL;

		if (firstNode == NULL)
		{
			firstNode = newnode;
			lastNode = newnode;
		}
		else
		{
			newnode->leftNode = lastNode;
			lastNode->rightNode = newnode;
			lastNode = lastNode->rightNode;
		}

		itemCount++;
	}

	int GetFirstIndexOf(int item)
	{
		int index = 0;
		Node* node = firstNode;
		while (node != NULL)
		{
			if (node->value == item)
				return index;

			index++;
			node = node->rightNode;
		}
		return -1;
	}

	bool GetItemAt(int index, int* item)
	{
		Node* node = firstNode;
		while (node != NULL)
		{
			if (index == 0)
			{
				*item = node->value;
				return true;
			}

			index--;
			node = node->rightNode;
		}
		return false;
	}

	bool RemoveItemAt(int index)
	{
		Node* node = firstNode;
		while (node != NULL)
		{
			if (index == 0)
			{
				Node* prev = node->leftNode;
				prev->rightNode = node->rightNode;
				delete node;
				itemCount--;
				return true;
			}

			index--;
			node = node->rightNode;
		}
		return false;
	}

	int GetItemCount()
	{
		return itemCount;
	}

	void PrintAll()
	{
		Node* node = firstNode;
		while (node != NULL)
		{
			printf("%d ", node->value);
			node = node->rightNode;
		}
	}
};

void LinkedListUsageExample()
{
	printf("\n\n03. LinkedListUsageExample: ");

	LinkedList* list = new LinkedList();

	printf("\nItem Added: ");
	for (int i = 1; i <= 10; i++)
	{
		printf("%d ", i);
		list->AddItem(i);
	}

	int item = 5;
	int indx = list->GetFirstIndexOf(item);
	printf("\nIndex of: %d -> %d", item, indx);

	int item2 = 0;
	bool result1 = list->GetItemAt(indx, &item2);
	printf("\nItem At: %d -> %d", indx, item2);

	bool result2 = list->RemoveItemAt(indx);
	printf("\nRemoved Item At: %d -> %s", indx, result2 ? "OK" : "FAIL");

	int count = list->GetItemCount();
	printf("\nPrintAll %d:", count);
	list->PrintAll();
}