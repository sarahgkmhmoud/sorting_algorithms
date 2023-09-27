#include"sort.h"
/**
 *count_sort - subfunction
 *@array: array
 *@size: size of array
 *@place: place
*/
void count_sort(int *array, size_t size, int place)
{
	int *countarray, *outputarray;
	size_t i;
	int j;

	countarray = malloc(sizeof(int) * 10);
	if (countarray == NULL)
	return;

	for (i = 0; i < 10; i++)
	countarray[i] = 0;


	for (i = 0; i < size; i++)
	countarray[(array[i] / place) % 10]++;

	for (i = 1; i < 10; i++)
	countarray[i] += countarray[i - 1];

	outputarray = malloc(sizeof(int) * (size + 1));
	if (outputarray == NULL)
{
	free(countarray);
	exit(EXIT_FAILURE);
}
	for (j = size - 1; j >= 0; j--)
	{
		outputarray[countarray[(array[j] / place) % 10] - 1] = array[j];
		countarray[(array[j] / place) % 10]--;
	}
	for (i = 0; i < size; i++)
	array[i] = outputarray[i];

	free(countarray);
	free(outputarray);
}
/**
 *radix_sort - using radix sort
 *@array: array
 *@size: sizeofarray
*/
void radix_sort(int *array, size_t size)
{
	size_t i;
	int place;
	int max;

	if (array == NULL || size < 2)
	return;

		max = array[0];

	for (i = 1; i < size; i++)
		{
		if (array[i] > max)
			max = array[i];
		}

	for (place = 1; max / place > 0; place *= 10)
		{
		count_sort(array, size, place);
		print_array(array, size);
		}
}
