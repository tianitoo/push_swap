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
	while (!stack_is_empty(stk))
	{
		ft_printf("%d\n", stk->value);
		stk = stk->next;
	}
}

stack push_stack(stack stk, int i)
{
	element *e;

	e = malloc(sizeof(*e));
	if(e == NULL)
		exit(0);
	e->value = i;
	e->next = stk;
	return (e);
}

stack pop_stack(stack stk)
{
	element *e;

	if (stack_is_empty(stk))
		return (NULL);
	e = stk->next;
	free(stk);
	stk = NULL;
	return (e);
}

int	top_stack(stack stk)
{
	return (stk->value);
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
	{
		// print_stack(stk);
		stk = pop_stack(stk);
	}
	return (stk);
}

int main()
{
	stack stk;

	stk = new_stack();
	stk = push_stack(stk, 7);
	stk = push_stack(stk, 2);
	stk = push_stack(stk, 9);
	stk = push_stack(stk, 5);
	// print_stack(stk);
	// stk = pop_stack(stk);
	// stk = clear_stack(stk);
	print_stack(stk);
	stk = push_swap(stk);
	print_stack(stk);

}