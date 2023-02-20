#include "sort.h"

/**
 * swap_listint_t - Swaps two nodes of a listint_t.
 *
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 * @list: List
 */
void swap_listint_t(listint_t *a, listint_t *b, listint_t **list)
{
	listint_t *c, *d;

	c = a->next;
	d = b->prev;
	if (c)
		c->prev = b;
	if (d)
		d->next = a;
	a->prev = d;
	b->next = c;
	a->next = b;
	b->prev = a;
	if (*list == b)
		*list = a;
	print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm.
 *
 * @list: The doubly linked list to sort.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *cur, *head, *tail;

	if (!list || !*list || !(*list)->next)
		return;
	cur = *list;
	head = tail = NULL;
	do {
		while (cur->next)
		{
			if (cur->n > cur->next->n)
				swap_listint_t(cur->next, cur, list);
			else
				cur = cur->next;
		}
		tail = cur;
		while (cur->prev != head)
		{
			if (cur->n < cur->prev->n)
				swap_listint_t(cur, cur->prev, list);
			else
				cur = cur->prev;
		}
		head = cur;
	} while (head != tail);
}
