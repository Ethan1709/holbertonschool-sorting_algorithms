#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	quick_sort_recursion(array, 0, size - 1, size);
}

/**
 * swap - swap values in array
 * @val1: first element to swap
 * @val2: second element to swap
 * Return: void
 */

void swap(int *val1, int *val2)
{
	int temp;

	temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

/**
 * partition - sections an array using quick_sort algo
 *		with Lomuto scheme
 * @array: array of integers
 * @low: lowest index of the array
 * @high: highest index of the array
 * @size: size of the array
 * Return: position of pivot in array
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot_value = array[high];
	int i = low - 1, j;

	for (j = low; j <= high; j++)
	{
		if (array[j] <= pivot_value)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	return (i);
}

/**
 * quick_sort_recursion - recursive quick sort function
 * @array: array of integers
 * @low: lowest index of the array
 * @high: highest index of the array
 * @size: size of the array
 * Return: void
 */

void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);

		quick_sort_recursion(array, low, pivot - 1, size);
		quick_sort_recursion(array, pivot + 1, high, size);
	}
}
