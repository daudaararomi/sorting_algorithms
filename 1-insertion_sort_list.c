#include "sort.h"

/**
 * swap_nodes - Swap two nodes  doubly-linked list.
 * @head: A pointer to the head .
 * @nod1: A pointer to the first node to swap.
 * @nod2: The second node to swap.
 */
void swap_nodes(listint_t **head, listint_t **nod1, listint_t *nod2)
{
	(*nod1)->next = nod2->next;
	if (nod2->next != NULL)
		nod2->next->prev = *nod1;
	nod2->prev = (*nod1)->prev;
	nod2->next = *nod1;
	if ((*nod1)->prev != NULL)
		(*nod1)->prev->next = nod2;
	else
		*head = nod2;
	(*nod1)->prev = nod2;
	*nod1 = nod2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
