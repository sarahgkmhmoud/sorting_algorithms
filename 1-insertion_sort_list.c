#include "sort.h"

/**
 * insertion_sort_list -  sorts a doubly linked list of integers
 * in ascending order usig Insertion sort algorithm
 *
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *ptr1, *ptr2;

	ptr2 = (*list)->next;
	while(ptr2 != NULL)
	{
		ptr1 = ptr2->prev;
		if (ptr2->n >= ptr1->n)
		{
			print_list(*list);
			return;
		}
		while(ptr2->n < ptr1->n || ptr1 != NULL)
		{
			ptr1 = ptr1->prev;
		}
		temp = ptr2->next;
		ptr2->prev->next = ptr2->next;
		ptr2->next->prev = ptr2->prev;
		
		if (ptr1 == NULL)
		{
			(*list)->next->prev = ptr2;
			ptr2->next = *list;
			*list = ptr2;
		
		}
		else
		{
			ptr1->next->prev = ptr2;
			ptr2->next = ptr1->next;
			ptr1->next = ptr2;
		}
		ptr2->prev = ptr1;
		print_list(*list);
		ptr2 = temp;

	}
	print_list(*list);
}
