#include "sort.h"

/**
 * bitonic_sort_recursive - Recursively sorts a bitonic sequence.
 * @array: The array to be sorted.
 * @low: Starting index of the sequence.
 * @count: Number of elements to sort.
 * @order: 1 if sorting in ascending order, 0 for descending order.
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int order)
{
	size_t k;

	if (count > 1)
	{
		k = count / 2;
		bitonic_sort_recursive(array, low, k, 1);
		bitonic_sort_recursive(array, low + k, k, 0);
		bitonic_merge(array, low, count, order);
	}
}

/**
 * bitonic_merge - Merges two bitonic sequences.
 * @array: The array to be sorted.
 * @low: Starting index of the sequence.
 * @count: Number of elements to merge.
 * @order: 1 if merging in ascending order, 0 for descending order.
 */
void bitonic_merge(int *array, size_t low, size_t count, int order)
{
	size_t k = count / 2;
	size_t i, temp;

	if (count > 1)
	{
		for (i = low; i < low + k; i++)
		{
			if ((array[i] > array[i + k]) == order)
			{
				temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;
				print_array(array, count);
			}
		}

		bitonic_merge(array, low, k, order);
		bitonic_merge(array, low + k, k, order);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic Sort.
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_recursive(array, 0, size, 1);
}

