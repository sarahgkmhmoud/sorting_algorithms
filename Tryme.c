

#include "sort.h"

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

size_t partition(int *array, size_t low, size_t high, size_t size)
{
    int pivot = array[high];
    size_t j;
    size_t i = low - 1;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }

    swap(&array[i + 1], &array[high]);
                print_array(array, size);

    return i + 1;
}

void quicksort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
    if (low < high)
    {
        size_t pivot = partition(array, low, high, size);

        quicksort_recursive(array, low, pivot - 1, size);
        quicksort_recursive(array, pivot + 1, high, size);
    }
}

void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_recursive(array, 0, size - 1, size);
}



