#include <iostream>
#include "CommonLibs.h"
using namespace std;

int linear_search(int arr[], int length, int val)
{
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == val)
		{
			return i;
		}
	}

	return -1;
}

int binary_search_algo(int arr[], int left, int right, int val)
{
	if (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (arr[mid] == val)
		{
			return mid;
		}

		if (arr[mid] > val)
		{
			return binary_search_algo(arr, left, mid - 1, val);
		}

		return binary_search_algo(arr, mid + 1, right, val);
	}

	return -1;
}

void SearchingAlgosUsageExample()
{
	printf("\n\n08. SearchingAlgosUsageExample: ");
	
	int numbers[] = { 20, 25, 30, 35, 40, 45 };
	int length = sizeof(numbers) / sizeof(numbers[0]);

	printf("\nNumbers: ");
	display_array(numbers, length);

	int searchval = 35;
	//printf("\nInput search value: ");
	//int inputlength = scanf("%d", &searchval);

	int index1 = linear_search(numbers, length, searchval);
	printf("\nLinier search index %d: %d", searchval, index1);

	int index2 = binary_search_algo(numbers, 0, length - 1, searchval);
	printf("\nBinary search index %d: %d", searchval, index2);
}
