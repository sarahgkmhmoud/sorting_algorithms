#include "sort.h"
/**
 *bubble_sort - sort the array by using bubble sort algorithm
 *@array: the array of  int element
 *@size: size of array
*/
void bubble_sort(int *array, size_t size)
{
	int a = 0;
	int b;
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		b = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j + 1] <= array[j])
			{
				b = 1;
				a = array[j];
				array[j] = array[j + 1];
				array[j + 1] = a;
				print_array(array, size);
			}
		}
		if(b == 0)
		break;
	}
}
