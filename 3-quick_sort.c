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
 *partitions - get the value
 *@array: array
 *@low: size_t low
 *@high: size_t high
 *@size: size_t size
 *Return: i+1 always success
*/
size_t partitions(int *array, size_t low, size_t high, size_t size)
{
int pivot;
size_t i, j;
pivot = array[high];
i = low - 1;
for (j = low; j < high; j++)
{
	if (array[j] < pivot)
	{
	i++;
	if (i != j)
	{
	swap(&array[i], &array[j]);
	if (array[i] != array[j])
	print_array(array, size);
	}
	}

}
	swap(&array[i + 1], &array[high]);
	if (array[i + 1] != array[high])
	print_array(array, size);
		return (i + 1);
}

/**
 *quic_rec - recursion
 *@array: array
 *@low: ssize_t
 *@high: ssize_t
 *@size: size_t
*/
void quic_rec(int *array, ssize_t low, ssize_t high, size_t size)
{

	if (low < high)
	{
	size_t pivot = partitions(array, low, high, size);

	quic_rec(array, low, pivot - 1, size);
	quic_rec(array, pivot + 1, high, size);
	}
}

/**
 *quick_sort - sorting
 *@array: array
 *@size: size
*/
void quick_sort(int *array, size_t size)
{
		if (array == NULL || size < 2)
		return;
quic_rec(array, 0, size - 1, size);
}
