#include "sort.h"

/**
 * max_knuth_seq_lt_n - Get biggest Knuth sequence element less than size.
 *
 * @size: Size
 * Return: Biggest Knuth sequence element less than size.
 */
size_t max_knuth_seq_lt_n(size_t size)
{
	size_t n = 1;

	while (n < size)
	{
		if (n * 3 + 1 >= size)
			break;
		n = n * 3 + 1;
	}
	return (n);
}

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

	n = max_knuth_seq_lt_n(size);
	for (gap = n; gap > 0; gap = (gap - 1) / 3)
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
