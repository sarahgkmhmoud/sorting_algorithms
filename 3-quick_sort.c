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
for(j = low; j < high; j++)
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
        return i+1;
}

/**
 * 
 * 
 * 
 * 
*/
void quic_rec(int *array, ssize_t low, ssize_t high, size_t size)
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
        if (array == NULL || size < 2)
        return;
quic_rec(array, 0, size - 1, size);
}
