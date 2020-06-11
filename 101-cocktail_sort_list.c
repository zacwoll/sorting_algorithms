#include "sort.h"

/**
 * swap - swaps 2 nodes in a doubly linked list
 * @a: address of first node
 * @b: address of second node
 */
void swap(listint_t *a, listint_t *b)
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

void cocktail_sort_list(listint_t **list)
{
	listint_t *i = *list;
	bool unsorted = true;

	if (!list || !*list)
		return;
	while (unsorted)
	{
		unsorted = false;
		while (i && i->next)
		{
			if (i->n > i->next->n)
			{
				swap(i, i->next);
				if (i->prev->prev == NULL)
					*list = i->prev;
				print_list(*list);
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
			if (i->prev->n > i->n)
			{
				swap(i->prev, i);
				if (i->prev == NULL)
					*list = i;
				print_list(*list);
				unsorted = true;
			}
			else
				i = i->prev;
		}
	}
}
