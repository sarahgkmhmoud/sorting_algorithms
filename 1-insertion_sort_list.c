#include "sort.h"

/**
 * insertion_sort_list -  sorts a doubly linked list of integers
 * in ascending order usig Insertion sort algorithm
 *
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp1, *temp2, *ptr2;

	if (*list == NULL || (*list)->next == NULL || list == NULL)
		return;

	ptr2 = (*list)->next;
	temp1 = NULL;
	temp2 = NULL;

	while (ptr2 != NULL)
	{
		temp2 = ptr2->prev;

		while (temp2 != NULL && ptr2->n < temp2->n)
		{
			temp1 = ptr2;
			temp2->next = ptr2->next;
			ptr2->prev = temp2->prev;
			if (ptr2->next)
			ptr2->next->prev = temp2;
			if (temp2->prev)
			temp2->prev->next = ptr2;
			ptr2->next = temp2;
			temp2->prev = ptr2;
			if (!ptr2->prev)
			*list = ptr2;
			print_list(*list);
			if (ptr2->n > temp2->n)
				{
				ptr2 = temp1;
				}
			temp2 = ptr2->prev;
		}
		ptr2 = ptr2->next;
	}
}
