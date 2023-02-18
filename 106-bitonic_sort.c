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
 * compare_and_swap - Swap elements depending on direction of sort.
 *
 * @a: Pointer to first element.
 * @b: Pointer to second element.
 * @up: Direction to sort.
 */
void compare_and_swap(int *a, int *b, int up)
{
	if (up == (*a > *b))
		swap(a, b);
}

/**
 * bitonic_merge - Recursively sorts a bitonic sequence in the order
 *                 specified by up.
 *
 * @array: Array to sorted.
 * @start: Start index of the sequence.
 * @size: Number of elements in the sequence.
 * @up: 1 if sequence is to be sorted in ascending order, 0 otherwise.
 */
void bitonic_merge(int *array, int start, int size, int up)
{
	int i, k;

	if (size > 1)
	{
		k = size / 2;
		for (i = start; i < start + k; i++)
			compare_and_swap(array + i, array + i + k, up);
		bitonic_merge(array, start, k, up);
		bitonic_merge(array, start + k, k, up);
	}
}

/**
 * bitonic_sort_helper - Recursively sorts the two halves of the array in
 *                       opposite orders to produces a bitonic sequence, then
 *                       merges them bitonically so they are sorted in the
 *                       same order.
 *
 * @array: Array with items to sort.
 * @size: Number of elements in the original array.
 * @start: Start index of range to consider.
 * @end: End index of range to consider.
 * @up: 1 if range should be sorted in ascending order, 0 otherwise.
 */
void bitonic_sort_helper(int *array, int size, int start, int end, int up)
{
	int mid = (start + end) / 2;

	if (end - start >= 1)
	{
		printf("Merging [%d/%d] (%s):\n",
			   end - start + 1, size, up ? "UP" : "DOWN");
		print_array(array + start, end - start + 1);

		bitonic_sort_helper(array, size, start, mid, 1);
		bitonic_sort_helper(array, size, mid + 1, end, 0);
		bitonic_merge(array, start, end - start + 1, up);

		printf("Result [%d/%d] (%s):\n",
			   end - start + 1, size, up ? "UP" : "DOWN");
		print_array(array + start, end - start + 1);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 *                using the Bitonic sort algorithm.
 *
 * @array: Array with elements to sort.
 * @size: Number of elements in the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	bitonic_sort_helper(array, size, 0, size - 1, 1);
}
