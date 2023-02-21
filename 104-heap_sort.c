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
 * sift_down - Repair the heap whose root element is at index @start, assuming
 *             the heaps rooted at its children are valid.
 *
 * @array: Array containing heap whose root element is at index @start.
 * @start: Index of root of heap to repair.
 * @end: End index of heap to repair.
 * @size: Number of elements in @array.
 */
void sift_down(int *array, int start, int end, size_t size)
{
	int root, child, candidate;

	root = start;
	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		candidate = root;
		if (array[candidate] < array[child])
			candidate = child;
		if (child + 1 <= end && array[candidate] < array[child + 1])
			candidate = child + 1;
		if (candidate != root)
		{
			swap(array + root, array + candidate);
			print_array((const int *)array, size);
			root = candidate;
		}
		else
		{
			return;
		}
	}
}

/**
 * heapify - Puts elements of array in heap order, in-place.
 *
 * @array: Array to heapify.
 * @size: Number of elements in the array.
 */
void heapify(int *array, size_t size)
{
	int start = (size - 2) / 2;

	while (start >= 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the Heap sort algorithm.
 *
 * @array: Array to be sorted.
 * @size: Number of elements in the array.
 */
void heap_sort(int *array, size_t size)
{
	int end;

	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		swap(array + end, array);
		print_array((const int *)array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}
