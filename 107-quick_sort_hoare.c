#include "sort.h"
#include <stdio.h>

/**
 * swap - Swap two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using Quick sort algorithm (Hoare partition scheme)
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    void quicksort(int *array, int lo, int hi, size_t size);
    quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - Recursive function to perform Quick sort using Hoare partition scheme
 * @array: Array to be sorted
 * @lo: Starting index of the partition to be sorted
 * @hi: Ending index of the partition to be sorted
 * @size: Size of the array
 */
void quicksort(int *array, int lo, int hi, size_t size)
{
    if (lo < hi)
    {
        int p = hoare_partition(array, lo, hi, size);
        quicksort(array, lo, p, size);
        quicksort(array, p + 1, hi, size);
    }
}

/**
 * hoare_partition - Partitions the array using Hoare partition scheme
 * @array: Array to be partitioned
 * @lo: Starting index of the partition
 * @hi: Ending index of the partition
 * @size: Size of the array
 *
 * Return: Index of the pivot element after partitioning
 */
int hoare_partition(int *array, int lo, int hi, size_t size)
{
    int pivot = array[hi];
    int i = lo - 1;
    int j = hi + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(&array[i], &array[j]);
        print_array(array, size);
    }
}

