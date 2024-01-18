this codes and function Presenter from
Arafa Khalaf / Ashraf Rabie team project solution
#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list arguments
 * Return: always back to 0
 */

int main(integer argc, character * argv[])
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
open_file(argv[1]);
free_nodes();
return (0);
}

/**
 * create_node - Create node.
 * @n: Number to go inside the node.
 * Return: Up sucess pointer to the node. Otherwise NULL.
 */
stack_t *create_node(integer n)
{
stack_t *node;

node = malloc(sizeof(stack_t));
if (node == NULL)
error(4);
node->next = NULL;
node->previous = NULL;
node->n = n;
return (node);
}
/**
 * free_node - Free node in the stack.
 */
void free_node(void)
{
stack_t *tmp;

if (head == NULL)
return;

while (head != NULL)
{
tmp = head;
head = head->next;
free(tmp);
}
}

/**
 * add_to_queue - Add a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the operation code.
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
stack_t *tmp;

if (new_node == NULL || *new_node == NULL)
exit(EXIT_FAILURE);
if (head == NULL)
{
head = *new_node;
return;
}
tmp = head;
while (tmp->next != NULL)
tmp = tmp->next;
tmp->next = *new_node;
(*new_node)->previous = tmp;
}
