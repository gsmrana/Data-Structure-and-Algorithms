#include <iostream>
#include <string.h>
using namespace std;

#define QUEUE_SIZE 5

class Queue
{
private:
	int head;
	int tail;
	int data[QUEUE_SIZE + 1];

public:
	Queue()
	{
		head = 0;	// dequeue from head then increment
		tail = 0;	// enqueue at tail then increment
		memset(data, 0, QUEUE_SIZE + 1);
	}

	bool Enqueue(int item)
	{
		int nextidx = (tail + 1) % (QUEUE_SIZE + 1);
		if (nextidx == head) //full
			return false;

		data[tail] = item;
		tail = nextidx;
		return true;
	}

	bool Dequeue(int* item)
	{
		if (tail == head) //empty
			return false;

		*item = data[head];
		head = (head + 1) % (QUEUE_SIZE + 1);
		return true;
	}

	bool Peek(int* item)
	{
		if (tail == head)
			return false;

		*item = data[head];
		return true;
	}

	bool PeekAtDepth(int* item, int depth)
	{
		if (tail == head)
			return false;

		int idx = (head + depth) % (QUEUE_SIZE + 1);
		*item = data[idx];
		return true;
	}

	int Count()
	{
		if (head == (tail + 1))
			return QUEUE_SIZE;
		return abs(tail - head);
	}

	void PrintAll()
	{
		for (int i = 0; i < Count(); i++)
		{
			int val;
			PeekAtDepth(&val, i);
			printf("%d ", val);
		}
	}
};

void QueueUsageExample()
{
	printf("\n\n02. QueueUsageExample: ");

	Queue queue;
	bool result;

	// underflow case
	int item = 0;
	result = queue.Dequeue(&item);
	if (!result)
		printf("\nFailed to Dequeue, Queue is empty!");

	// insert within capacity
	queue.Enqueue(10);
	queue.Enqueue(20);
	queue.Enqueue(30);
	queue.Enqueue(40);
	queue.Enqueue(50);

	printf("\nQueue Items: ");
	queue.PrintAll();

	// remove test
	result = queue.Dequeue(&item);
	if (result)
		printf("\nQueue item removed");

	// overflow case
	queue.Enqueue(60);
	result = queue.Enqueue(70);
	if (!result)
		printf("\nFailed to Enqueue, Queue is full!");

	printf("\nQueue Items: ");
	queue.PrintAll();
}
