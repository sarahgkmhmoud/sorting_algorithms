#include "sort.h"
/**
 *selection_sort - sort the array by using selection sort algorithm
 *@array: the array of  int element
 *@size: size of array
*/
void selection_sort(int *array, size_t size)
{
	size_t minindx, a;
	size_t i, j;

	a = 0;
	if (!array || size < 2)
	return;
	for (i = 0; i < size - 1; i++)
	{
		minindx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minindx])
				minindx = j;
		}
		if (minindx != i)
		{
			a = array[minindx];
			array[minindx] = array[i];
			array[i] = a;
			print_array(array, size);
		}
	}
}
