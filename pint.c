#include "monty.h"

/**
 * f_pint - Prints the value of the top element in the stack
 * @head: Pointer to the stack's head
 * @counter: Line number
 * Return: No return value
 */
void f_pint(stack_t **head, unsigned int counter)
{
    if (!*head)
    {
        fprintf(stderr, "L%u: stack empty\n", counter);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*head)->n);
}

