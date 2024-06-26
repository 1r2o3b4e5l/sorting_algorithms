#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                      using the Cocktail shaker sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *start = *list;
    listint_t *end = NULL;

    if (list == NULL || *list == NULL)
        return;

    while (swapped)
    {
        swapped = 0;
        while (start->next != end)
        {
            if (start->n > start->next->n)
            {
                swap_nodes(list, start, start->next);
                print_list(*list);
                swapped = 1;
            }
            else
                start = start->next;
        }

        if (!swapped)
            break;

        swapped = 0;
        end = start;
        while (start->prev != NULL)
        {
            if (start->n < start->prev->n)
            {
                swap_nodes(list, start->prev, start);
                print_list(*list);
                swapped = 1;
            }
            else
                start = start->prev;
        }
    }
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the doubly linked list
 * @node1: First node to be swapped
 * @node2: Second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (*list == NULL || node1 == NULL || node2 == NULL)
        return;

    if (node1->prev != NULL)
        node1->prev->next = node2;
    else
        *list = node2;

    if (node2->next != NULL)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;
}

