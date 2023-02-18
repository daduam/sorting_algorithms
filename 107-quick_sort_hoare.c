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
	int i, j, pivot = array[hi];

	for (i = lo, j = hi; 1; i++, j--)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i >= j)
			return (i);
		swap(array + i, array + j);
		print_array((const int *)array, size);
	}
}

/**
 * quick_sort_helper - Sorts a portion of an array, divides it into partitions,
 *                     then sorts those.
 *
 * @array: Array to sort.
 * @lo: Index of the lower bound of the array.
 * @hi: Index of the upper bound of the array.
 * @size: The number of integers in the array.
 */
void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quick_sort_helper(array, lo, pivot - 1, size);
		quick_sort_helper(array, pivot, hi, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *                    using the Quick sort algorithm with Hoare
 *                    partition scheme.
 *
 * @array: The array to be sorted.
 * @size: The number of integers in the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}
