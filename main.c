#include "monty.h"
#include <stdio.h>

/**
 * main - Monty interpreter for code
 * @argc: Number of arguments
 * @argv: Monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    FILE *file;
    stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty filename\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (read_line(&bus.content, &bus.size, file) != -1)
    {
        bus.counter++;
        execute(bus.content, &stack, bus.counter, file);
        free(bus.content);
        bus.content = NULL;
    }

    free_stack(stack);
    fclose(file);

    return (EXIT_SUCCESS);
}

