#include "push_swap.h"

// create empty stack
stack new_stack()
{
	return (NULL);
}

// check is stack is empty
Bool	stack_is_empty(stack stk)
{
	if (stk == NULL)
		return (True);
	return (False);
}

void	print_stack(stack stk)
{
	// ft_printf("_______\n");
	while (!stack_is_empty(stk))
	{
		ft_printf("%d ", stk->value);
		stk = stk->next;
	}
	ft_printf("\n");

}

stack push_stack(stack stk, int i)
{
	element *e;

	e = malloc(sizeof(*e));
	if(e == NULL)
	{
		exit(0);
	}
	e->value = i;
	e->next = stk;
	return (e);
}

void pop_stack(stack *stk)
{
	element *e;

	if (stack_is_empty(*stk))
		return ;
	e = (*stk)->next;
	free(*stk);
	*stk = NULL;
	*stk = e;
}

int	top_stack(stack stk)
{
	return (stk->value);
}

stack *tail_stack(stack *stk)
{
	stack *tail;

	tail = stk;
	if(stack_is_empty(*tail))
		return (tail);
	while(!stack_is_empty((*tail)->next))
	{
		tail = &(*tail)->next;
	}
	return (tail);
}

int	stack_length(stack stk)
{
	int length;

	length = 0;
	while(!stack_is_empty(stk))
	{
		length++;
		stk = stk->next;
	}
	return (length);
}

stack	clear_stack(stack stk)
{
	while (!stack_is_empty(stk))
		pop_stack(&stk);
	return (stk);
}
