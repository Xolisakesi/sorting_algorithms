#include "sort.h"

/**
* cocktail_sort_list - Sort a doubly linked list using Cocktail Shaker sort
* @list: Pointer to the doubly linked list
*/
void cocktail_sort_list(listint_t **list)
{
listint_t *current, *next, *prev;
int swapped = 1;

if (list == NULL || *list == NULL)
return;

while (swapped)
{
swapped = 0;

/* Forward pass */
for (current = *list; current->next != NULL; current = next)
{
next = current->next;
if (current->n > next->n)
{
if (current->prev != NULL)
current->prev->next = next;
else
*list = next;

next->prev = current->prev;
current->prev = next;
current->next = next->next;

if (next->next != NULL)
next->next->prev = current;

next->next = current;
swapped = 1;
print_list(*list);
}
}

if (!swapped)
break;

swapped = 0;

/* Backward pass */
for (; current->prev != NULL; current = prev)
{
prev = current->prev;
if (prev->n > current->n)
{
if (prev->prev != NULL)
prev->prev->next = current;
else
*list = current;

current->prev = prev->prev;
prev->prev = current;
prev->next = current->next;

if (current->next != NULL)
current->next->prev = prev;

current->next = prev;
swapped = 1;
print_list(*list);
}
}
}
}

