#ifndef DECK_H
#define DECK_H

/* includes */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * enum kind_e - Suit of card
 * @SPADE: value 0
 * @HEART: value 1
 * @CLUB: value 2
 * @DIAMOND: value 3
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/* prototypes */
void cocktail_sort_deck(deck_node_t **deck);
void swap(deck_node_t *a, deck_node_t *b);
bool card_compare(const card_t *a, const card_t *b);
void sort_deck(deck_node_t **deck);
#endif /* DECK_H */
