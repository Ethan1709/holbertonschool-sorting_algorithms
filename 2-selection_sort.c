#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - function that sorts an array of int in ascending order
 * @array: array to sort
 * @size: size of array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	int tmp = 0;
	size_t tmpi;
	size_t i = 0;
	size_t j = 0;

	for (i = 0; i < size; i++)
	{
		tmpi = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[tmpi] > array[j])
				tmpi = j;
		}
		if (tmpi != i)
		{
			tmp = array[i];
			array[i] = array[tmpi];
			array[tmpi] = tmp;
			print_array(array, size);
		}
	}
}
