//Normal EVMs there are 256-bit numbers, but since im starting imma just use standard integers and upgrade to bit numbers later

#ifndef STACK_H
# define STACK_H

#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX_SIZE 1024

typedef struct s_stack{
	int data[STACK_MAX_SIZE];
	int stack_pointer;
}	t_stack;

void	push(t_stack *stack, int value);
int     pop(t_stack *stack);

#endif