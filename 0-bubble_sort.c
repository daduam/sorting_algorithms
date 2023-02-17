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
 * bubble_sort - Sorts an array of integers in ascending order using
 *               the Bubble sort algorithm.
 *
 * @array: The array to sort.
 * @size: Number of integers in the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, swapped;

	swapped = 1;
	while (swapped)
	{
		i = 1, swapped = 0;
		while (i < size && (array + i - 1) && (array + i))
		{
			if (*(array + i - 1) > *(array + i))
			{
				swap(array + i - 1, array + i);
				swapped = 1;
				print_array(array, size);
			}
			i++;
		}
	}
}
