#include "sort.h"

/**
 * swap - Swaps two integers.
 *
 * @a: The first integer.
 * @b: The second integer.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The number of integers in the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size; i++)
		if (!(array + i))
			return;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (*(array + j) < *(array + min))
				min = j;
		if (min != i)
		{
			swap(array + i, array + min);
			print_array((const int *)array, size);
		}
	}
}
