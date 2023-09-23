#include "sort.h"

/**
 * insertion_sort_list -  sorts a doubly linked list of integers
 * in ascending order usig Insertion sort algorithm
 *
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp1, *temp2, *ptr1, *ptr2;
	if (*list == NULL || (*list)->next == NULL)
		return;

	ptr2 = (*list)->next;
	while(ptr2 != NULL)
	{
		ptr1 = ptr2->prev;
		temp2 = ptr2->next;
		while(ptr2->n < ptr1->n || ptr1 != NULL)
		{
			temp1 = ptr1->prev;
			ptr1->next = ptr2->next;
			ptr2->next->prev = ptr1;
			if(ptr1->prev != NULL)
			{
				ptr1->prev->next = ptr2;
				ptr1->prev = ptr2;
			}
			else
			{
				*list = ptr2;
			}
			ptr2->prev = ptr1->prev;
			print_list(*list);
			ptr1 = temp1;
		}
		ptr2 = temp2;
	}
}
