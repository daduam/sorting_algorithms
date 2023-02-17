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
 * partition - Divides the array into two partitions.
 *
 * @array: Array to partition.
 * @lo: Index of the lower bound of the array.
 * @hi: Index of the upper bound of the array.
 * @size: The number of integers in the array.
 * Return: The pivot index.
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot, i, j;

	pivot = *(array + hi);
	i = lo - 1;
	for (j = lo; j < hi; j++)
	{
		if (*(array + j) <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(array + i, array + j);
				print_array((const int *)array, size);
			}
		}
	}
	i++;
	if (i != hi)
	{
		swap(array + i, array + hi);
		print_array((const int *)array, size);
	}
	return (i);
}

/**
 * quick_sort_helper - Sorts a portion of an array, divides it into
 *                     partitions, then sorts those.
 *
 * @array: Array to sort.
 * @lo: Index of the lower bound of the array.
 * @hi: Index of the upper bound of the array.
 * @size: The number of integers in the array.
 */
void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo >= hi || lo < 0)
		return;
	p = partition(array, lo, hi, size);
	quick_sort_helper(array, lo, p - 1, size);
	quick_sort_helper(array, p + 1, hi, size);
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The number of integers in the array.
 */
void quick_sort(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		if (!(array + i))
			return;

	quick_sort_helper(array, 0, size - 1, size);
}
