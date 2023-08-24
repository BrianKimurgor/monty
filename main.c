#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

bus_t bus = {0};

int main(int argc, char *argv[]) {
    FILE *file;
    char *content = NULL;
    size_t content_size = 0;
    unsigned int counter = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&content, &content_size, file) > 0) {
        execute(content, &bus, counter, file);
        free(content);
        content = NULL;
        counter++;
    }

    fclose(file);
    free_stack(bus.stack);

    return 0;
}

