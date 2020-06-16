#include "deck.h"

/**
 * swap - swaps 2 nodes in a doubly linked deck
 * @a: address of first node
 * @b: address of second node
 */
void swap(deck_node_t *a, deck_node_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * card_compare - compares two cards, swaps if b < a
 * @a: card A
 * @b: card B
 * Return: true if b < a, false otherwise
 */
bool card_compare(const card_t *a, const card_t *b)
{
	char *values[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
		"10", "Jack", "Queen", "King"};
	int i, j;

	if (a->kind > b->kind)
		return (true);
	else if (a->kind < b->kind)
		return (false);

	for (i = 0; i < 13; i++)
		if (!strcmp(a->value, values[i]))
			break;
	for (j = 0; j < 13; j++)
		if (!strcmp(b->value, values[j]))
			break;
	if (j < i)
		return (true);
	else
		return (false);
}

/**
 * cocktail_sort_deck - sorts deck using cocktail sort
 * @deck: deck of cards to be sorted
 */
void cocktail_sort_deck(deck_node_t **deck)
{
	deck_node_t *i = *deck;
	bool unsorted = true;

	if (!deck || !*deck)
		return;
	while (unsorted)
	{
		unsorted = false;
		while (i && i->next)
		{
			if (card_compare(i->card, i->next->card))
			{
				swap(i, i->next);
				if (i->prev->prev == NULL)
					*deck = i->prev;
				unsorted = true;
			}
			else
				i = i->next;
		}
		if (!unsorted)
			break;
		unsorted = false;
		while (i->prev)
		{
			if (card_compare(i->prev->card, i->card))
			{
				swap(i->prev, i);
				if (i->prev == NULL)
					*deck = i;
				unsorted = true;
			}
			else
				i = i->prev;
		}
	}
}

/**
 * sort_deck - sorts deck of cards by calling cocktail_sort_deck
 * @deck: deck of cards
 */
void sort_deck(deck_node_t **deck)
{
	cocktail_sort_deck(deck);
}
