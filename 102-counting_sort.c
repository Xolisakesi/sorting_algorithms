#include "sort.h"

/**
* counting_sort - Sorts an array of integers in ascending order
* using the Counting sort algorithm
* @array: The array to be sorted
* @size: Size of the array
*/
void counting_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

counting_sort_helper(array, size);
}

/**
* counting_sort_helper - Helper function for Counting Sort
* @array: The array to be sorted
* @size: Size of the array
*/
void counting_sort_helper(int *array, size_t size)
{
int max, i;
int *count, *output;

max = array[0];

for (i = 1; i < (int)size; i++)
{
if (array[i] > max)
max = array[i];
}

count = malloc((max + 1) * sizeof(int));
if (count == NULL)
return;

output = malloc(size * sizeof(int));
if (output == NULL)
{
free(count);
return;
}

for (i = 0; i <= max; i++)
count[i] = 0;

for (i = 0; i < (int)size; i++)
count[array[i]]++;

print_array(count, max + 1);

for (i = 1; i <= max; i++)
count[i] += count[i - 1];

for (i = size - 1; i >= 0; i--)
{
output[count[array[i]] - 1] = array[i];
count[array[i]]--;
}

for (i = 0; i < (int)size; i++)
array[i] = output[i];

free(count);
free(output);
}

