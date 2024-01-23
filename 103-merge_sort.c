#include "sort.h"
#include <stdlib.h>

/**
* merge - Merge two subarrays.
* @array: The array to be sorted.
* @left: Pointer to the left subarray.
* @left_size: Size of the left subarray.
* @right: Pointer to the right subarray.
* @right_size: Size of the right subarray.
*/
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
size_t i = 0, j = 0, k = 0;
int *merged;
printf("Merging...\n[left]: ");
print_array(left, left_size);
printf("[right]: ");
print_array(right, right_size);

merged = malloc((left_size + right_size) * sizeof(int));

if (merged == NULL)
{
free(merged);
return;
}

while (i < left_size && j < right_size)
{
if (left[i] <= right[j])
{
merged[k] = left[i];
i++;
}
else
{
merged[k] = right[j];
j++;
}
k++;
}

while (i < left_size)
{
merged[k] = left[i];
i++;
k++;
}

while (j < right_size)
{
merged[k] = right[j];
j++;
k++;
}

for (k = 0; k < left_size + right_size; k++)
array[k] = merged[k];

printf("[Done]: ");
print_array(array, left_size + right_size);

free(merged);
}

/**
* merge_sort - Sort an array of integers in ascending order using Merge Sort.
* @array: The array to be sorted.
* @size: The size of the array.
*/
void merge_sort(int *array, size_t size)
{
size_t mid;
int *left, *right;
if (array == NULL || size < 2)
return;

mid = size / 2;
left = array;
right = array + mid;

printf("\n");
print_array(array, size);

if (size > 1)
{
merge_sort(left, mid);
merge_sort(right, size - mid);
merge(array, left, mid, right, size - mid);
}
}

