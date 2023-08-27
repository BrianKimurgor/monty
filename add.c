#include "monty.h"

/**
 * f_add - Adds the top two elements of the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty bytecode file
 *
 * Description: This function adds the values of the top two elements of the
 * stack and replaces the top element with the result.
 * If there are less than two elements in the stack, an error message is
 * printed and the program exits with failure status.
 */
void f_add(stack_t **stack, unsigned int line_number)
{
    stack_t *top = *stack;
    stack_t *second_top = top->next;

    if (top == NULL || second_top == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    top->n += second_top->n;
    *stack = second_top;
    free(top);
}

