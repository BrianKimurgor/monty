#include "monty.h"

/**
 * f_stack - Switches the interpreter to stack mode
 * @head: Pointer to the stack's head
 * @counter: Line number being executed
 * Return: No return value
 */
void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}

