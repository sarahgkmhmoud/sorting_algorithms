#include "sort.h"
/**
 *bubble_sort - sort the array by using bubble sort algorithm
 *@array: the array of  int element
 *@size: size of array
*/
void bubble_sort(int *array, size_t size)
{
	int a = 0;
	size_t i, j;

	if (!array || size < 2)
	return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j + 1] < array[j])
			{
				a = array[j];
				array[j] = array[j + 1];
				array[j + 1] = a;
				print_array(array, size);
			}
		}
	}
}
