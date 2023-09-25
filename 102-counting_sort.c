#include"sort.h"
/**
 *counting_sort - using counting sort algorithm
 *@array: integer array
 *@size: size of array
*/
void counting_sort(int *array, size_t size)
{
	size_t i, m;
	int *countarray, *outputarray;
	int j, max;

	if (array == NULL || size < 2)
	return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		max = array[i];
	}
	m = max + 1;
	countarray = malloc(sizeof(int) * (m));
	if (countarray == NULL)
	return;
	for (i = 0; i < m ; i++)
	countarray[i] = 0;
	for (i = 0; i < size; i++)
	countarray[array[i]]++;
	for (i = 1; i < m; i++)
	countarray[i] += countarray[i - 1];
	print_array(countarray, m);
	outputarray = malloc(sizeof(int) * size + 1);
	if (outputarray == NULL)
	{
	free(countarray);
	return;
	}
	for (j = (int) size - 1; j >= 0; j--)
	{
	outputarray[countarray[array[j]] - 1] = array[j];
	countarray[array[j]]--;
	}
	for (i = 0; i < size; i++)
	array[i] = outputarray[i];
	free(countarray);
	free(outputarray);
}
