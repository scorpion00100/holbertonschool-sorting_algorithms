#include "sort.h"

/**
 * swap_dlist - Swap two elements in a double linked list
 * @hi: higher element
 * @lo: lower element
 */
void swap_dlist(listint_t *hi, listint_t *lo)
{
	hi->next = lo->next;

	if (hi->prev)
		hi->prev->next = lo;
	if (lo->next)
		lo->next->prev = hi;

	lo->next = hi;
	lo->prev = hi->prev;
	hi->prev = lo;
}

/**
 * insertion_sort_list - Implement insertion sort algorithm
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL, *tmp2 = NULL;

	if (list == NULL)
		return;

	/* iterate in the list only if it exists */
	for (tmp = *list; tmp; tmp = tmp->next)
	{
		tmp2 = tmp;

		/* swap while there are a high and low elements */
		while (tmp2->prev && (tmp2->n < tmp2->prev->n))
		{
			swap_dlist(tmp2->prev, tmp2);

			/**
			 * if there is not more swapable elements and if the node
			 * is the new head of the list.
			 * set the partial list to **list
			 */
			if (!tmp2->prev)
				*list = tmp2;

			print_list(*list);
		}
	}
}
