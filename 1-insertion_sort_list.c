#include "sort.h"

/**
 * swap_listint_t - Swaps two nodes of a listint_t.
 *
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 */
void swap_listint_t(listint_t *a, listint_t *b)
{
	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	b->next = a;

	b->prev = a->prev;
	if (a->prev)
		a->prev->next = b;
	a->prev = b;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm.
 *
 * @list: Address of the head of the doubly linked list to sort.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (!list || !(*list))
		return;

	i = (*list)->next;
	while (i)
	{
		j = i;
		i = i->next;
		while (j && j->prev)
		{
			if (j->prev->n > j->n)
			{
				swap_listint_t(j->prev, j);
				if (!j->prev)
					*list = j;
				print_list((const listint_t *)*list);
			}
			else
			{
				j = j->prev;
			}
		}
	}
}
