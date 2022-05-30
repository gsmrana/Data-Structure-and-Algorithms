#include <iostream>
#include "CommonLibs.h"
using namespace std;


void sorting_BubbleSortAsc(int* buf, int len)
{
	bool sorted = false;

	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i < (len - 1); i++)
		{
			if (buf[i] > buf[i + 1])
			{
				swap(buf[i], buf[i + 1]);
				sorted = false;
			}
		}
	}
}

// take the left element as pivot
// place the smallest element to left
// plece the largest element to right
// swap the pivot element to its correct position
int QuickSortAsc_Partition2(int* buf, int left, int right)
{
	int pivot = buf[left];
	int pivot_index = left;
	for (int i = left + 1; i <= right; i++)
	{
		if (buf[i] <= pivot)
		{
			pivot_index++;
			swap(buf[i], buf[pivot_index]);
		}
	}

	swap(buf[left], buf[pivot_index]);
	return pivot_index;
}

void sorting_QuickSortAsc(int* buf, int left, int right)
{
	if (left >= right)
		return;

	// randomize the left pivot value
	int k = left + rand() % (right - left + 1);
	swap(buf[left], buf[k]);

	int pi = QuickSortAsc_Partition2(buf, left, right);
	sorting_QuickSortAsc(buf, left, pi - 1);
	sorting_QuickSortAsc(buf, pi + 1, right);
}

// merge two sorted array and build one sorted array
void sorting_MergeArrayAsc(int* buf, int left, int mid, int right)
{
	int leftsize = mid - left + 1;
	int rightsize = right - mid;
	int* leftarr = new int[leftsize];
	int* rightarr = new int[rightsize];

	for (int i = 0; i < leftsize; i++)
		leftarr[i] = buf[left + i];

	for (int i = 0; i < rightsize; i++)
		rightarr[i] = buf[mid + i + 1];

	int i = 0, j = 0, k = left;
	while (i < leftsize && j < rightsize)
	{
		if (leftarr[i] < rightarr[j])
			buf[k++] = leftarr[i++];
		else
			buf[k++] = rightarr[j++];
	}

	while (i < leftsize)
	{
		buf[k++] = leftarr[i++];
	}

	while (j < rightsize)
	{
		buf[k++] = rightarr[j++];
	}
}

void sorting_MergeSortAsc(int* buf, int left, int right)
{
	if (left >= right)
		return;

	int mid = left + ((right - left) / 2);
	sorting_MergeSortAsc(buf, left, mid);
	sorting_MergeSortAsc(buf, mid + 1, right);

	sorting_MergeArrayAsc(buf, left, mid, right);
}

// create Max Heap from parentIndex 
// to all decendent child nodes recursively
void sorting_Heapify(int* buf, int parentIndex, int length)
{
	int left = (parentIndex * 2) + 1;
	int right = (parentIndex * 2) + 2;
	int swapChild = parentIndex;

	if (left < length && buf[left] > buf[swapChild])
		swapChild = left;

	if (right < length && buf[right] > buf[swapChild])
		swapChild = right;

	if (swapChild != parentIndex)
	{
		// swap parent with largest child
		swap(buf[parentIndex], buf[swapChild]);

		// heapify again from the swapped node
		sorting_Heapify(buf, swapChild, length);
	}
}

void sorting_HeapSortAsc(int* buf, int length)
{
	// create Max Heap
	// starting from bottom internal node
	int lastParent = (length / 2) - 1;
	while (lastParent >= 0)
	{
		sorting_Heapify(buf, lastParent, length);
		lastParent--;
	}

	int lastChild = length - 1;
	while (lastChild > 0)
	{
		// swap the max value (root node)
		// with the last unsorted position
		swap(buf[0], buf[lastChild]);

		// create max heap again from root 
		// to remaining unsorted items 
		sorting_Heapify(buf, 0, lastChild);
		lastChild--;
	}
}

void SortingAlgosUsageExample()
{
	printf("\n\n09. SortingAlgosUsageExample: ");

	int numbers[] = { 5, 3, 1, 4, 6, 9, 7, 0, 2, 8 };
	int length = sizeof(numbers) / sizeof(numbers[0]);

	printf("\nInput Values: ");
	display_array(numbers, length);

	sorting_BubbleSortAsc(numbers, length);
	printf("\nBubbleSortAsc result: ");
	display_array(numbers, length);

	sorting_QuickSortAsc(numbers, 0, length - 1);
	printf("\nQuickSortAsc result : ");
	display_array(numbers, length);

	sorting_MergeSortAsc(numbers, 0, length - 1);
	printf("\nMergeSortAsc result : ");
	display_array(numbers, length);

	sorting_HeapSortAsc(numbers, length);
	printf("\nHeapSortAsc result  : ");
	display_array(numbers, length);
}
