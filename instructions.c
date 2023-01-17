#include "push_swap.h"

void push_a(stack *a, stack *b)
{
	element *e;

	if (stack_is_empty(*b))
	{
		return ;
	}
	*a = push_stack(*a, (*b)->value);
	pop_stack(b);
	ft_printf("pa\n");
}

void push_b(stack *a, stack *b)
{
	element *e;

	if (stack_is_empty(*a))
	{
		return ;
	}
	*b = push_stack(*b, (*a)->value);
	pop_stack(a);
	ft_printf("pb\n");
}

stack swap_a(stack stk)
{
	int a;
	int b;

	a = top_stack(stk);
	pop_stack(&stk);
	b = top_stack(stk);
	pop_stack(&stk);
	stk = push_stack(stk, a);
	stk = push_stack(stk, b);
	ft_printf("sa\n");
	return (stk);
}

stack swap_b(stack stk)
{
	int a;
	int b;

	a = top_stack(stk);
	pop_stack(&stk);
	b = top_stack(stk);
	pop_stack(&stk);
	stk = push_stack(stk, a);
	stk = push_stack(stk, b);
	ft_printf("sb\n");
	return (stk);
}

void rotate_a(stack *a)
{
	element *e;

	e = new_stack();
	if(stack_is_empty(*a) || stack_length(*a) == 1)
		return ;
	e = push_stack(e, top_stack(*a));
	pop_stack(a);
	(*tail_stack(a))->next = e;
	ft_printf("ra\n");
}

void rotate_b(stack *b)
{
	element *e;

	e = new_stack();
	if(stack_is_empty(*b) || stack_length(*b) == 1)
		return ;
	e = push_stack(e, top_stack(*b));
	pop_stack(b);
	(*tail_stack(b))->next = e;
	ft_printf("rb\n");
}

void rotate_back_a(stack *a)
{
	int e;
	stack *pop;

	e = (*tail_stack(a))->value;
	pop = tail_stack(a);
	pop_stack(pop);
	*a = push_stack(*a, e);
	ft_printf("rra\n");
}

void rotate_back_b(stack *b)
{
	int e;
	stack *pop;

	e = (*tail_stack(b))->value;
	pop = tail_stack(b);
	pop_stack(pop);
	*b = push_stack(*b, e);
	ft_printf("rrb\n");
}