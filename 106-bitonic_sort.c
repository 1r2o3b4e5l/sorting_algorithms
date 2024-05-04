#include "sort.h"

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort algorithm
 * @array: Array of integers to be sorted
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_recursive(array, size, 1, size);
}

/**
 * bitonic_recursive - Recursively divides and merges the array in a bitonic manner
 * @array: Array of integers to be sorted
 * @size: Size of the array
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 * @n: Size of the subarray to be operated on
 */
void bitonic_recursive(int *array, size_t size, int dir, size_t n)
{
    if (n > 1)
    {
        size_t k = n / 2;
        printf("Merging [%lu/%lu] (%s):\n", n, size, dir ? "UP" : "DOWN");
        print_array(array, n);
        bitonic_recursive(array, size, 1, k);
        bitonic_recursive(array + k, size, 0, k);
        bitonic_merge(array, n, dir);
        printf("Result [%lu/%lu] (%s):\n", n, size, dir ? "UP" : "DOWN");
        print_array(array, n);
    }
}

/**
 * bitonic_merge - Merges two subarrays in a bitonic manner
 * @array: Array of integers to be sorted
 * @n: Size of the subarray to be merged
 * @dir: Direction of merging (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t n, int dir)
{
    if (n > 1)
    {
        size_t k = n / 2;
        int i, temp;

        for (i = 0; i < (int)n - k; i++)
        {
            if ((array[i] > array[i + k]) == dir)
            {
                temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;
                printf("Swap %d with %d\n", array[i], array[i + k]);
            }
        }

        bitonic_merge(array, k, dir);
        bitonic_merge(array + k, k, dir);
    }
}

