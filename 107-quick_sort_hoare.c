#include"sort.h"
/**
 *swap - swap the integers
 *@x: integer
 *@y: integer
*/
void swap(int *x, int *y)
{
int temp = 0;
temp = *x;
*x = *y;
*y = temp;
}

/**
 *partitions_hoare - get the value
 *@array: array
 *@low: size_t low
 *@high: size_t high
 *@size: size_t size
 *Return: j on success
*/
size_t partitions_hoare(int *array, size_t low, size_t high, size_t size)
{
int pivot;
size_t i, j;

pivot = array[high];
i = low - 1;
j = high + 1;
while (1)
{
	do {
		i++;
	} while (array[i] < pivot);
	do {
		j--;
	} while (array[j] > pivot);
	if (i >= j)
		return (i);

	swap(&array[i], &array[j]);
	print_array(array, size);

}

}

/**
 *quic_rec_hoare - recursion
 *@array: array
 *@low: ssize_t
 *@high: ssize_t
 *@size: size_t
*/
void quic_rec_hoare(int *array, ssize_t low, ssize_t high, size_t size)
{

	if (low < high)
	{
	size_t pivot = partitions_hoare(array, low, high, size);

	quic_rec_hoare(array, low, pivot - 1, size);
	quic_rec_hoare(array, pivot, high, size);
	}
}

/**
 *quick_sort - sorting
 *@array: array
 *@size: size
*/
void quick_sort_hoare(int *array, size_t size)
{
		if (array == NULL || size < 2)
		return;
quic_rec_hoare(array, 0, size - 1, size);
}
