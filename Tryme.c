#include"sort.h"
/**
 *bubble_sort - sort the array by using bubble sort algorithm
 *@array: the array of  int element
 *@size: size of array
*/
void insertion_sort_list(listint_t **list)
{
	listint_t  *current, *tmp;

	current = (*list)->next;
    tmp =  NULL;

    while (current)
    {
        if (current->n < current->prev->n)
        {
      printf("after if condition 1\n"); 

        tmp = current->prev;
        while(tmp->prev)
        {
       printf("start the loop\n");
       printf("current->n = %i\n",current->n);
            if (tmp->n < current->n)
            {
        printf("after if condition 2\n"); 

          current->next->prev = current->prev;
        printf("current->next->prev = current->prev\n");
          current->prev->next = current->next;
          printf("current->prev->next = current->next;\n");
          tmp->next->prev = current;
                  printf(" tmp->next->prev = current;\n");
          tmp->next = current;
          printf(" tmp->next = current;\n");

          current->prev = tmp;
          printf(" current->prev = tmp;\n"); 
        break;
            }
            tmp = tmp->prev;

         if (tmp->prev == NULL)
        {
        printf("tmp->prev is null\n");
       current->next->prev = current->prev;
          current->prev->next = current->next;
          tmp->next->prev = current;
          tmp->next = current;
          current->prev = tmp;
          *list = current; 
          break;
        }
          print_list(*list);
        }
       
        }
        current = current->next;
     }
    }
