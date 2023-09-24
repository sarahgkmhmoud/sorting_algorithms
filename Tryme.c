#include"sort.h"
/**
 *
 * 
 * 
 * 
*/
void swap(int *x,int *y)
{
int temp = 0;
temp = *x;
*x = *y;
*y = temp;
}
/**
 * 
 * 
 * 
 * 
*/
size_t partitions(int *array, size_t low, size_t high, size_t size)
{
int pivot;
size_t i, j;
pivot = array[high];
i = low - 1;
for(j = low; j <= high - 1; j++)
{
    if (array[j] < pivot)
    {
    i++;
    swap(&array[i], &array[j]);
    if (array[i] != array[j])
    print_array(array, size);
    }
}
    swap(&array[i], &array[high]);
    if (array[i] != array[high])
    print_array(array, size);
        return i+1;
}

/**
 * 
 * 
 * 
 * 
*/
void quic_rec(int *array, size_t low, size_t high, size_t size)
{

    if (low < high)
    {
      size_t pivot = partitions(array, low, high, size);
      quic_rec(array, low, pivot - 1, size);
      quic_rec(array, pivot + 1, high, size);  
    }
    return;
}
/**
 *
 * 
 *
*/
void quick_sort(int *array, size_t size)
{
quic_rec(array, 0, size - 1, size);
}
