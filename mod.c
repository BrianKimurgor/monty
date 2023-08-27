#include "monty.h"

/**
 * f_mod - Computes the rest of the division of the second
 *         top element of the stack by the top element of the stack
 * @head: Stack head
 * @line_number: Line number
 */
void f_mod(stack_t **head, unsigned int line_number)
{
	stack_t *h = *head;
	unsigned int len = 0;
	int aux;

	while (h)
	{
		len++;
		h = h->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%u: stack too short\n", line_number);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (h->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	aux = (h->prev->n) % (h->n);
	h->prev->n = aux;
	free(h);
	*head = h->prev;
}

