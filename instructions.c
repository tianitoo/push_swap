#include "push_swap.h"

stack push_swap(stack a)
{
	stack b;

	push_ab(&a, &b);
	return (a);
}

void push_ab(stack *a, stack *b)
{
	element *e;

	*b = push_stack(*b, (*a)->value);
	*a = pop_stack(*a);
}

void swap_stack(stack *stk)
{
	
}