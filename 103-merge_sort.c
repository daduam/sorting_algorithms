#include "sort.h"

/**
 * copy_array - Copies elements in a[] to b[].
 *
 * @a: Source array.
 * @ibegin: Begin index.
 * @iend: End index.
 * @b: Destination array.
 */
void copy_array(int *a, int ibegin, int iend, int *b)
{
	int k;

	for (k = ibegin; k < iend; k++)
		b[k] = a[k];
}

/**
 * top_down_merge - Merges the left source half (a[ibegin:imiddle-1]) and
 *                  right source half (a[imiddle:iend-1]) into one result
 *                  array (b[ibegin:iend-1]).
 *
 * @a: Array with items to sort.
 * @ibegin: Begin index.
 * @imiddle: Middle index.
 * @iend: End index.
 * @b: Work array.
 */
void top_down_merge(int *a, int ibegin, int imiddle, int iend, int *b)
{
	int i, j, k;

	printf("Merging...\n");

	printf("[left]: %d", a[ibegin]);
	for (i = ibegin + 1; i < imiddle; i++)
		printf(", %d", a[i]);
	printf("\n");

	printf("[right]: %d", a[imiddle]);
	for (j = imiddle + 1; j < iend; j++)
		printf(", %d", a[j]);
	printf("\n");

	i = ibegin, j = imiddle;
	for (k = ibegin; k < iend; k++)
	{
		if (i < imiddle && (j >= iend || a[i] <= a[j]))
			b[k] = a[i++];
		else
			b[k] = a[j++];
	}

	printf("[Done]: %d", b[ibegin]);
	for (k = ibegin + 1; k < iend; k++)
		printf(", %d", b[k]);
	printf("\n");
}

/**
 * top_down_split_merge - Splits a[] into 2 runs, sorts both runs into b[],
 *                        and merges both runs from b[] to a[].
 *
 * @b: Work array.
 * @ibegin: Begin index.
 * @iend: End index.
 * @a: Array with items to sort.
 */
void top_down_split_merge(int *b, int ibegin, int iend, int *a)
{
	int imiddle;

	if (iend - ibegin <= 1)
		return;
	imiddle = (iend + ibegin) / 2;
	top_down_split_merge(a, ibegin, imiddle, b);
	top_down_split_merge(a, imiddle, iend, b);
	top_down_merge(b, ibegin, imiddle, iend, a);
}

/**
 * top_down_merge_sort - Performs a top-down merge sort on a[].
 *
 * @a: Array with items to sort.
 * @b: Work array.
 * @n: Number of items in a[].
 */
void top_down_merge_sort(int *a, int *b, size_t n)
{
	copy_array(a, 0, n, b);
	top_down_split_merge(b, 0, n, a);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm.
 *
 * @array: Array to be sorted.
 * @size: Number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int i, *work;

	for (i = 0; i < (int)size; i++)
		if (!(array + i))
			return;
	work = malloc(sizeof(int) * size);
	if (!work)
		return;
	top_down_merge_sort(array, work, size);
	free(work);
}
