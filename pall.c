#include "monty.h"

/**
 * f_pall - Prints all elements of the stack
 * @head: Pointer to the stack's head
 * @counter: Line number (unused)
 * Return: No return value
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;
	(void)counter;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

