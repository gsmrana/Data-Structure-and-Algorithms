#include <iostream>
using namespace std;

void display_array(int arr[], int length);

void sort_BubbleSortAsc(int arr[], int length)
{
	bool sorted = false;

	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i < (length - 1); i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				sorted = false;
			}
		}
	}
}

void SortingAlgosUsageExample()
{
	printf("\n\n09. SortingAlgosUsageExample: ");

	int numbers[] = { 5, 7, 2, 10, 4, 6, 9, 1, 8, 3 };
	int length = sizeof(numbers) / sizeof(numbers[0]);

	printf("\nBefore Sorting: ");
	display_array(numbers, length);

	sort_BubbleSortAsc(numbers, length);
	printf("\nAfter Sorting : ");
	display_array(numbers, length);
}
