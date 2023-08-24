#include "monty.h"

/**
 * f_div - Divides the second element from the top by the top element.
 * @head: A pointer to the head of the stack.
 * @counter: The line number in the Monty file.
 *
 * Return: No return value.
 */
void f_div(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		len++;
		h = h->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}

	if (h->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", counter);
		exit(EXIT_FAILURE);
	}

	aux = h->next->n / h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}

