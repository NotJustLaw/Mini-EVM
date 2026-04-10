#include "stack.h"

void    push(t_stack *stack, int value)
{
    if (stack->stack_pointer >= STACK_MAX_SIZE)
    {
        fprintf(stderr, "[Error]: Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->data[stack->stack_pointer] = value;
    stack->stack_pointer++;
}

int     pop(t_stack *stack)
{
    if (stack->stack_pointer == 0)
    {
        fprintf(stderr, "[Error]: Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    stack->stack_pointer--;
    return (stack->data[stack->stack_pointer]);
}