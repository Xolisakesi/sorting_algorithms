#include "deck.h"
#include <stdlib.h>

int compare_cards(const void *a, const void *b) {
    const deck_node_t *node_a = *(const deck_node_t **)a;
    const deck_node_t *node_b = *(const deck_node_t **)b;

    // Compare values first
    int value_cmp = strcmp(node_a->card->value, node_b->card->value);
    if (value_cmp != 0) {
        return value_cmp;
    }

    // If values are equal, compare kinds
    return node_a->card->kind - node_b->card->kind;
}

void sort_deck(deck_node_t **deck) {
    size_t count = 52;
    deck_node_t *nodes[52];

    // Create an array of pointers to deck nodes
    for (size_t i = 0; i < count; ++i) {
        nodes[i] = *deck;
        *deck = (*deck)->next;
    }

    // Use qsort to sort the array of pointers
    qsort(nodes, count, sizeof(deck_node_t *), compare_cards);

    // Reconstruct the doubly linked list in sorted order
    for (size_t i = 0; i < count - 1; ++i) {
        nodes[i]->next = nodes[i + 1];
        nodes[i + 1]->prev = nodes[i];
    }

    nodes[0]->prev = NULL;
    nodes[count - 1]->next = NULL;

    *deck = nodes[0];
}

