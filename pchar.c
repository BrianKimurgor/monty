#include "monty.h"

/**
 * f_pchar - Prints the character at the top of the stack
 * @head: Pointer to the stack's head
 * @counter: Line number
 * Return: No return value
 */
void f_pchar(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%u: stack empty\n", counter);
		exit(EXIT_FAILURE);
	}
	if (h->n < 0 || h->n > 127)
	{
		fprintf(stderr, "L%u: cannot print char %d\n", counter, h->n);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}

