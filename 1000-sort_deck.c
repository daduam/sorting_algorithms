#include "deck.h"
/**
 * swap_deck_nodes - Swaps two nodes of a deck.
 *
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 */
void swap_deck_nodes(deck_node_t *a, deck_node_t *b)
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
 * _strcmp - String compare
 *
 * @s1: String 1
 * @s2: String 2
 * Return: int
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * compare_cards - Compares two cards.
 *
 * @a: Card 1
 * @b: Card 2
 * Return: int
 */
int compare_cards(deck_node_t *a, deck_node_t *b)
{
	int i, arank, brank;

	char ranks[13][6] = {"Ace", "2", "3", "4", "5", "6", "7",
						 "8", "9", "10", "Jack", "Queen", "King"};
	for (i = 0; i < 13; i++)
	{
		if (_strcmp(ranks[i], a->card->value) == 0)
			arank = i;
		if (_strcmp(ranks[i], b->card->value) == 0)
			brank = i;
	}
	if (b->card->kind == a->card->kind)
		return (brank - arank);
	return (b->card->kind - a->card->kind);
}

/**
 * insertion_sort_deck - Sort deck by insertion sort.
 *
 * @deck: Deck.
 */
void insertion_sort_deck(deck_node_t **deck)
{
	deck_node_t *i, *j;

	if (!deck || !(*deck))
		return;
	i = (*deck)->next;
	while (i)
	{
		j = i;
		i = i->next;
		while (j && j->prev)
		{
			if (compare_cards(j->prev, j) < 0)
			{
				swap_deck_nodes(j->prev, j);
				if (!j->prev)
					*deck = j;
			}
			else
			{
				j = j->prev;
			}
		}
	}
}

/**
 * sort_deck - Sorts the deck.
 *
 * @deck: Deck.
 */
void sort_deck(deck_node_t **deck)
{
	if (!deck)
		return;
	insertion_sort_deck(deck);
}
