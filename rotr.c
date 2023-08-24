#include "monty.h"

/**
 * f_rotr - Rotates the stack to the bottom.
 * @head: Pointer to the head of the stack.
 * @counter: Line number (unused).
 * Return: No return value.
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    stack_t *last, *secondLast;

    if (*head == NULL || (*head)->next == NULL)
        return;

    last = *head;
    secondLast = NULL;

    while (last->next != NULL)
    {
        secondLast = last;
        last = last->next;
    }

    secondLast->next = NULL;
    last->prev = NULL;
    last->next = *head;
    (*head)->prev = last;
    *head = last;
}

