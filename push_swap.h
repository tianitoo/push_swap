#ifndef __PUSH_SWAP__H__
# define __PUSH_SWAP__H__
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>

typedef enum
{
	False,
	True
} Bool;

typedef struct element
{
	int value;
	struct element *next;
}element, *stack;

stack new_stack();
stack	clear_stack(stack stk);
int	stack_length(stack stk);
int	top_stack(stack stk);
stack pop_stack(stack stk);
void	print_stack(stack stk);
stack push_stack(stack stk, int i);
stack push_swap(stack a);
void push_ab(stack *a, stack *b);



#endif