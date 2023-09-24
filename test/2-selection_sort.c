#include "sort.h"

/**
 * selection_sort -  sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * 
 * @array: pointer to the array
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t minindx, i, j, temp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minindx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minindx])
			{
				minindx = j;
			}
		}
		temp = array[minindx];
		array[minindx] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}
