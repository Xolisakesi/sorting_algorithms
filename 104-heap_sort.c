#include "sort.h"

/**
* swap - Swaps two integers in an array.
* @a: The first integer.
* @b: The second integer.
*/
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
* heapify - Turns an array into a max heap.
* @array: The array to heapify.
* @size: Size of the array.
* @i: Index of the root of the subtree.
* @total_size: Total size of the array.
*/
void heapify(int *array, size_t size, size_t i, size_t total_size)
{
size_t largest = i;
size_t left = 2 * i + 1;
size_t right = 2 * i + 2;

if (left < size && array[left] > array[largest])
largest = left;

if (right < size && array[right] > array[largest])
largest = right;

if (largest != i)
{
swap(&array[i], &array[largest]);
print_array(array, total_size);
heapify(array, size, largest, total_size);
}
}

/**
* heap_sort - Sorts an array of integers in ascending order using Heap Sort.
* @array: The array to be sorted.
* @size: Size of the array.
*/
void heap_sort(int *array, size_t size)
{
int i;
if (array == NULL || size < 2)
return;

for (i = size / 2 - 1; i >= 0; i--)
heapify(array, size, i, size);

for (i = size - 1; i > 0; i--)
{
swap(&array[0], &array[i]);
print_array(array, size);
heapify(array, i, 0, size);
}
}

