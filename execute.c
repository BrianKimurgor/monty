#include "monty.h"

/**
 * handle_unknown_instruction - Handles unknown instruction error
 * @counter: line_counter
 * @op: opcode
 * @file: pointer to monty file
 * @content: line content
 * @stack: head linked list - stack
 */
void handle_unknown_instruction(unsigned int counter, char *op,
FILE *file, char *content, stack_t **stack)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
	fclose(file);
	free(content);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * execute - Executes the opcode
 * @content: Line content
 * @stack: Head linked list - stack
 * @counter: Line counter
 * @file: Pointer to monty file
 * Return: 0 on success, 1 on failure
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"add", f_add},
		{NULL, NULL}
	};

	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
	{
		return (0);
	}

	bus.arg = strtok(NULL, " \n\t");

	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}

	if (op && opst[i].opcode == NULL)
	{
		handle_unknown_instruction(counter, op, file, content, stack);
	}

	return (1);
}

