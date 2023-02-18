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
 * sort_from_tail - Sorts from tail to head.
 *
 * @head: Head of the listint_t list.
 * @tail: Tail of the listint_t list.
 * @list: listint_t list.
 * Return: Head of sorted list.
 */
listint_t *sort_from_tail(listint_t *head, listint_t *tail, listint_t *list)
{
	while (tail && tail->prev)
	{
		if (tail->n < tail->prev->n)
		{
			swap_listint_t(tail->prev, tail);
			if (tail->prev == NULL)
				list = tail;
			print_list(list);
		}
		else
		{
			tail = tail->prev;
		}
		if (tail->prev == NULL)
			head = tail;
	}
	return (head);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm.
 *
 * @list: The doubly linked list to sort.
 */
void cocktail_sort_list(listint_t **list)
{
	int i, j;
	listint_t *head, *tail;

	if (list == NULL || *list == NULL)
		return;
	head = *list;
	for (i = 0; head; i++)
		head = head->next;
	if (i < 2)
		return;
	head = *list;
	while (j < i)
	{
		while (head && head->next)
		{
			if (head->n > head->next->n)
			{
				swap_listint_t(head, head->next);
				if (head->prev->prev == NULL)
					*list = head->prev;
				print_list((const listint_t *)*list);
			}
			else
			{
				head = head->next;
			}
			if (head->next == NULL)
				tail = head;
		}
		head = sort_from_tail(head, tail, *list);
		*list = head;
		j++;
	}
}
