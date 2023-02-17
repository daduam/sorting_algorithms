#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 *
 * @array: Array to be sorted.
 * @size: Number of elements in the array.
 */
void counting_sort(int *array, size_t size)
{
	int i, j, k, *count, *output;

	for (i = 0; i < (int)size; i++)
	{
		if (!(array + i))
			return;
		if (k < *(array + i))
			k = *(array + i);
	}
	count = malloc(sizeof(int) * (k + 1));
	if (!count)
		return;
	for (i = 0; i <= k; i++)
		*(count + i) = 0;
	for (i = 0; i < (int)size; i++)
	{
		j = *(array + i) - 1;
		*(count + j) += 1;
	}
	for (i = 1; i <= k; i++)
		*(count + i) += *(count + i - 1);
	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}
	for (i = size - 1; i >= 0; i--)
	{
		j = *(array + i) - 1;
		*(count + j) -= 1;
		*(output + *(count + j)) = *(array + i);
	}
	print_array((const int *)count, k + 1);
	for (i = 0; i < (int)size; i++)
		*(array + i) = *(output + i);
	free(count);
	free(output);
}
