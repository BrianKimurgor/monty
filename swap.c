#include "monty.h"

/**
 * f_swap - Swaps the top two elements of the stack.
 * @head: Double pointer to the head of the stack
 * @counter: Line number
 *
 * Return: No return value
 */
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *first;
	stack_t *second;
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	first = *head;
	second = (*head)->next;
	temp = first->n;
	first->n = second->n;
	second->n = temp;
}

