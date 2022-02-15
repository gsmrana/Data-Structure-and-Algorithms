#include <iostream>
#include <string.h>
using namespace std;

#define STACK_SIZE 5

class Stack
{
private:
	int top; //current item count
	int data[STACK_SIZE];

public:
	Stack()
	{
		top = 0;
		memset(data, 0, STACK_SIZE);
	}

	bool Push(int item)
	{
		if (top >= STACK_SIZE) //full
			return false;

		data[top] = item;
		top++;
		return true;
	}

	bool Pop(int* item)
	{
		if (top <= 0) //empty
			return false;

		top--;
		*item = data[top];
		return true;
	}

	bool Peek(int* item)
	{
		if (top <= 0)
			return false;

		*item = data[top - 1];
		return true;
	}

	int Count()
	{
		return top;
	}

	void PrintAll()
	{
		for (int i = (top - 1); i >= 0; i--)
		{
			printf("%d ", data[i]);
		}
	}
};

void StackUsageExample()
{
	printf("01. StackUsageExample: ");

	Stack stack;
	bool result;

	// underflow case
	int item = 0;
	result = stack.Pop(&item);
	if (!result)
		printf("\nFailed to Dequeue, Stack is empty!");

	// insert within capacity
	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	stack.Push(40);
	stack.Push(50);

	printf("\nStack Items: ");
	stack.PrintAll();

	// remove test
	result = stack.Pop(&item);
	if (result)
		printf("\nStack item removed");

	// overflow case
	stack.Push(60);
	result = stack.Push(70);
	if (!result)
		printf("\nFailed to Enqueue, Stack is full!");

	printf("\nStack Items: ");
	stack.PrintAll();
}
