#include "sort.h"
/**
 * find_max - Finds the maximum integer in an array.
 *
 * @array: Array to search.
 * @size: Number of elements in the array.
 * Return: Maximum integer in array.
 */
int find_max(int *array, size_t size)
{
	int i, k;

	k = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (k < array[i])
			k = array[i];
	}
	return (k);
}

/**
 * fill_with_zeros - Fill array with zeros.
 *
 * @array: Array.
 * @size: Length of the array.
 */
void fill_with_zeros(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		array[i] = 0;
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 *
 * @array: Array to be sorted.
 * @size: Number of elements in the array.
 */
void counting_sort(int *array, size_t size)
{
	int i, k, *count, *output;

	if (!array || size < 2)
		return;

	k = find_max(array, size);
	count = malloc(sizeof(int) * (k + 1));
	if (!count)
		return;
	fill_with_zeros(count, k + 1);

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 1; i <= k; i++)
		count[i] += count[i - 1];

	print_array((const int *)count, k + 1);

	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}

	for (i = size - 1; i >= 0; i--)
		output[--count[array[i]]] = array[i];

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
