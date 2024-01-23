#ifndef SORT_H
#define SORT_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quicksort(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void counting_sort(int *array, size_t size);
void counting_sort_helper(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size);
void merge_sort(int *array, size_t size);
void swap(int *a, int *b);
void heapify(int *array, size_t size, size_t i, size_t total_size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t low, size_t count, int order);
void bitonic_sort_recursive(int *array, size_t low, size_t count, int order);
void quick_sort_hoare(int *array, size_t size);
void hoare_quick_sort(int *array, ssize_t low, ssize_t high, size_t size);
ssize_t hoare_partition(int *array, ssize_t low, ssize_t high, size_t size);
void swap_elements(int *array, ssize_t a, ssize_t b, size_t size);

#endif /* SORT_H */
