#include "monty.h"

/**
 * f_push - adds a new node to the stack.
 * @head: stack head
 * @number: value to push onto the stack
 * Return: no return
 */
void f_push(stack_t **head, unsigned int number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = number;
	new_node->next = *head;
	*head = new_node;
}
