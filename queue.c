#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0, 0, 0, NULL, NULL};

/**
 * f_queue - sets the lifi flag to 1.
 * @head: Unused parameter.
 * @counter: Unused parameter.
 */
void f_queue(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    bus.lifi = 1;
}

/**
 * addqueue - adds a node to the end of the queue.
 * @head: Unused parameter.
 * @n: Value to be added.
 */
void addqueue(stack_t **head, int n)
{
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = n;
    new_node->prev = bus.tail;
    new_node->next = NULL;

    if (bus.tail == NULL)
    {
        bus.head = new_node;
    }
    else
    {
        bus.tail->next = new_node;
    }

    bus.tail = new_node;
}

