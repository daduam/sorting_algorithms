#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order
 *              using the Radix sort algorithm
 *
 * @array: Array to be sorted.
 * @size: Number of elements in the array.
 */
void radix_sort(int *array, size_t size)
{
	int i, place, *result, max, count[10];

	if (!array || size < 2)
		return;
	for (i = 0; i < (int)size; i++)
		if (!(array + i))
			return;
	place = 1;
	max = array[0];
	for (i = 1; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];
	result = malloc(sizeof(int) * size);
	if (!result)
		return;
	while (max / place > 0)
	{
		for (i = 0; i < 10; i++)
			count[i] = 0;
		for (i = 0; i < (int)size; i++)
			count[(array[i] / place) % 10]++;
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		for (i = size - 1; i >= 0; i--)
			result[--count[(array[i] / place) % 10]] = array[i];
		for (i = 0; i < (int)size; i++)
			array[i] = result[i];
		place *= 10;
		print_array((const int *)array, size);
	}
	free(result);
}
