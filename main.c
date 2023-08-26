#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0, 0, 0, NULL};

/**
 * main - Entry point for the Monty interpreter
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Always 0 on success
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char *content = NULL;
    size_t content_size = 0;
    unsigned int counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: could not open file '%s'\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Reading and Interpreting Monty Code */
    while(fgets(content, content_size, file) != NULL)
    {
        execute(content, &bus.stack, counter, file);
        free(content);
        content = NULL;
        counter++;
    }

    /* Cleanup */
    free_stack(bus.stack);
    fclose(file);
    return 0;
}

