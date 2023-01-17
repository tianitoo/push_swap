#ifndef __PUSH_SWAP__H__
# define __PUSH_SWAP__H__
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
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
void pop_stack(stack *stk);
void	print_stack(stack stk);
stack push_stack(stack stk, int i);
stack *push_swap(stack *a);
void push_a(stack *a, stack *b);
void push_b(stack *a, stack *b);
stack swap_a(stack stk);
stack swap_b(stack stk);
void rotate_a(stack *a);
void rotate_b(stack *b);
stack *tail_stack(stack *stk);
Bool	stack_is_empty(stack stk);
void rotate_back_a(stack *a);
void rotate_back_b(stack *b);
void	sort(stack *a, stack *b);
int	first(stack stk);
int second(stack stk);
int check_double(char **ss);
int last(stack stk);
void move_small(stack *a, int index, void (*rotate)(stack *a));



#endif