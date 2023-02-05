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
void push(stack *a, stack *b, char stk_name);
stack swap(stack stk, char stk_name);
void rotate(stack *a, char stk_name);
void rotate_back(stack *a, char stk_name);
stack *tail_stack(stack *stk);
Bool	stack_is_empty(stack stk);
void	sort(stack *a, stack *b);
int	first(stack stk);
void	five(stack *a, stack *b);
int second(stack stk);
Bool stack_is_sorted(stack stk);
int check_double(char **ss);
void	three(stack *stk, char stk_name);
int last(stack stk);
int find_small(stack stk);
void move_small(stack *a, int index, char name, void (*rotate)(stack *a, char stk_name));

#endif