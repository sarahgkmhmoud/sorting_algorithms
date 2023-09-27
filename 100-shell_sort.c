#include "sort.h"
/**
 *shell_sort - using shell sort
 *@array: the integer
 *@size: size_t size of arrray
*/
void shell_sort(int *array, size_t size)
{
size_t gap, i, j;
int tmp;
if (array == NULL || size < 2)
return;
/*generat knuth interval*/
gap = 1;
while (gap < size / 3)
gap = gap * 3 + 1;

for (; gap >= 1; gap /= 3)
{
	for (i = gap; i < size; i++)
	{
		tmp = array[i];
		for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
			array[j] = array[j - gap];
		array[j] = tmp;
	}
	print_array(array, size);
}
}
