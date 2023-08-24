#include "monty.h"

/**
 * f_swap - Swaps the top two elements of the stack.
 * @head: Pointer to the stack's head.
 * @counter: Line number.
 * Return: No return value.
 */
void f_swap(stack_t **head, unsigned int counter) {
    stack_t *h = *head;
    stack_t *tmp = *head;
    unsigned int len = 0;

    while (h) {
        h = h->next;
        len++;
    }

    if (len < 2) {
        fprintf(stderr, "Error: stack too short for swap at line %u\n", counter);
        exit(EXIT_FAILURE);
    }

    tmp = *head;
    *head = tmp->next;
    tmp->prev = tmp->next;
    tmp->next = (*head)->next;
    (*head)->prev = NULL;
    (*head)->next = tmp;
    tmp->next->prev = tmp;

    int tmp_n = tmp->n;
    tmp->n = (*head)->n;
    (*head)->n = tmp_n;
}

