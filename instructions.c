#include "push_swap.h"

void push(stack *a, stack *b, char stk)
{
	if (stk == 'a')
	{
		if (stack_is_empty(*b))
			return ;
		*a = push_stack(*a, (*b)->value);
		pop_stack(b);
		ft_printf("pa\n");
	}
	else
	{
		if (stack_is_empty(*a))
			return ;
		*b = push_stack(*b, (*a)->value);
		pop_stack(a);
		ft_printf("pb\n");
	}
}

stack swap(stack stk, char stack)
{
	int a;
	int b;

	a = top_stack(stk);
	pop_stack(&stk);
	b = top_stack(stk);
	pop_stack(&stk);
	stk = push_stack(stk, a);
	stk = push_stack(stk, b);
	ft_printf("s%c\n", stack);
	return (stk);
}

void rotate(stack *a, char stk)
{
	element *e;

	e = new_stack();
	if(stack_is_empty(*a) || stack_length(*a) == 1)
		return ;
	e = push_stack(e, top_stack(*a));
	pop_stack(a);
	(*tail_stack(a))->next = e;
	ft_printf("r%c\n", stk);
}

void rotate_back(stack *a, char stk)
{
	int e;
	stack *pop;

	e = (*tail_stack(a))->value;
	pop = tail_stack(a);
	pop_stack(pop);
	*a = push_stack(*a, e);
	ft_printf("rr%c\n", stk);
}
