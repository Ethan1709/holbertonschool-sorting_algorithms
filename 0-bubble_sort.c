#include "sort.h"

void bubble_sort(const int *array, size_t size)
{
	int temp = 0;
	size_t j, i = 0;

	if (size < 2)
		return;
	while (size - 1 - i)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
		i++;
	}
}
