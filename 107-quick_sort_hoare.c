#include "sort.h"

/**
* quick_sort_hoare - Sorts an array of integers in ascending order using
* the Quick sort algorithm with the Hoare partition scheme.
* @array: The array to be sorted.
* @size: Size of the array.
*/
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

hoare_quick_sort(array, 0, size - 1, size);
}

/**
* hoare_quick_sort - Implements the Hoare partition scheme for Quick sort.
* @array: The array to be sorted.
* @low: Starting index of the partition.
* @high: Ending index of the partition.
* @size: Size of the array.
*/
void hoare_quick_sort(int *array, ssize_t low, ssize_t high, size_t size)
{
ssize_t partition;

if (low < high)
{
partition = hoare_partition(array, low, high, size);
hoare_quick_sort(array, low, partition - 1, size);
hoare_quick_sort(array, partition + 1, high, size);
}
}

/**
* hoare_partition - Chooses the pivot and partitions the array accordingly.
* @array: The array to be partitioned.
* @low: Starting index of the partition.
* @high: Ending index of the partition.
* @size: Size of the array.
*
* Return: The final position of the pivot.
*/
ssize_t hoare_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
int pivot = array[high];
ssize_t i = low - 1, j = high + 1;

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

swap_elements(array, i, j, size);
}
}

/**
* swap_elements - Swaps two elements in an array and prints the array.
* @array: The array containing elements.
* @a: Index of the first element.
* @b: Index of the second element.
* @size: Size of the array.
*/
void swap_elements(int *array, ssize_t a, ssize_t b, size_t size)
{
int temp;

if (a != b)
{
temp = array[a];
array[a] = array[b];
array[b] = temp;
print_array(array, size);
}
}

