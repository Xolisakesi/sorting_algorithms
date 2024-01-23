#include "sort.h"

/**
* quick_sort - Sorts an array of integers in ascending order
* using the Quick sort algorithm with Lomuto partition scheme
* @array: The array to be sorted
* @size: Size of the array
*/
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quicksort(array, 0, size - 1, size);
}

/**
* quicksort - Recursive helper function for Quick Sort
* @array: The array to be sorted
* @low: Starting index of the partition to be sorted
* @high: Ending index of the partition to be sorted
* @size: Size of the array
*/
void quicksort(int *array, int low, int high, size_t size)
{
int partition_index;

if (low < high)
{
partition_index = lomuto_partition(array, low, high, size);
quicksort(array, low, partition_index - 1, size);
quicksort(array, partition_index + 1, high, size);
}
}

/**
* lomuto_partition - Lomuto partition scheme for Quick Sort
* @array: The array to be sorted
* @low: Starting index of the partition to be sorted
* @high: Ending index of the partition to be sorted
* @size: Size of the array
*
* Return: Partition index
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot, temp, i, j;

pivot = array[high];
i = low - 1;

for (j = low; j <= high - 1; j++)
{
if (array[j] <= pivot)
{
i++;
temp = array[i];
array[i] = array[j];
array[j] = temp;
if (i != j)
print_array(array, size);
}
}

temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;

print_array(array, size);

return (i + 1);
}

