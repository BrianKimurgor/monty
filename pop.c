#include "monty.h"

/**
 * f_pop - Removes the top element from the stack
 * @head: Double pointer to the head of the stack
 * @counter: Line number being executed
 *
 * Return: No return value
 */
void f_pop(stack_t **head, unsigned int counter)
{
    stack_t *h;

    if (*head == NULL)
    {
        fprintf(stderr, "L%d: stack underflow\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    h = *head;
    *head = (*head)->next;
    free(h);
}

