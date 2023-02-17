#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 *              the Shell sort algorithm, using the Knuth sequence.
 *
 * @array: Array to be sorted.
 * @size: Number of elements in the array.
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, n, gap;

	n = 1;
	while (n < size)
		n = n * 3 + 1;
	for (gap = (n - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = *(array + i);
			for (j = i; (j >= gap) && (*(array + j - gap) > temp); j -= gap)
				*(array + j) = *(array + j - gap);
			*(array + j) = temp;
		}
		print_array((const int *)array, size);
	}
}
