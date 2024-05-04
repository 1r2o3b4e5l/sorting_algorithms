#include "deck.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @a: First node to be swapped
 * @b: Second node to be swapped
 */
void swap_nodes(deck_node_t **a, deck_node_t **b)
{
    deck_node_t *temp = *a;
    *a = *b;
    *b = temp;

    if (*a)
        (*a)->prev = (*b)->prev;
    if (*b)
        (*b)->prev = temp->prev;
}

/**
 * partition - Partitions the deck using the last element as pivot
 * @deck: Deck to be partitioned
 * @low: Starting node of the partition
 * @high: Ending node of the partition
 *
 * Return: Node pointer to the pivot element after partitioning
 */
deck_node_t *partition(deck_node_t **deck, deck_node_t *low, deck_node_t *high)
{
    const card_t *pivot = high->card;
    deck_node_t *i = low->prev;

    for (deck_node_t *j = low; j != high; j = j->next)
    {
        if (j->card->kind < pivot->kind || (j->card->kind == pivot->kind && strcmp(j->card->value, pivot->value) < 0))
        {
            i = (i == NULL) ? low : i->next;
            swap_nodes(&i, &j);
        }
    }
    i = (i == NULL) ? low : i->next;
    swap_nodes(&i, &high);

    return i;
}

/**
 * quick_sort_deck - Recursive function to perform Quick sort on the deck
 * @deck: Deck to be sorted
 * @low: Starting node of the partition
 * @high: Ending node of the partition
 */
void quick_sort_deck(deck_node_t **deck, deck_node_t *low, deck_node_t *high)
{
    if (high != NULL && low != high && low != high->next)
    {
        deck_node_t *pivot = partition(deck, low, high);
        quick_sort_deck(deck, low, pivot->prev);
        quick_sort_deck(deck, pivot->next, high);
    }
}

/**
 * sort_deck - Sorts a deck of cards in ascending order using Quick sort algorithm
 * @deck: Pointer to the head of the doubly linked list representing the deck
 */
void sort_deck(deck_node_t **deck)
{
    if (*deck == NULL || (*deck)->next == NULL)
        return;

    deck_node_t *last = *deck;
    while (last->next)
        last = last->next;

    quick_sort_deck(deck, *deck, last);
}

