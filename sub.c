#include "monty.h"

/**
 * f_sub - Subtracts the top element of the stack from the second top element.
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty file
 * Return: No return value
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux = *head;
	int nodes = 0;
	int sus;

	while (aux != NULL)
	{
		nodes++;
		aux = aux->next;
	}

	if (nodes < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}

