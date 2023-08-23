#include "monty.h"

/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;
	int len = 0;
	int aux;
	stack_t *top;
	stack_t *next;

	while (h != NULL)
	{
		len++;
		h = h->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "Error: Stack is too short to perform addition on line %d.\n", counter);
		exit(1);
	}

	top = *head;
	next = top->next;
	aux = top->n + next->n;
	next->n = aux;
	*head = next;
	free(top);
}

