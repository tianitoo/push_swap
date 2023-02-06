/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:08:53 by hnait             #+#    #+#             */
/*   Updated: 2023/02/06 14:08:54 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (NULL);
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

int isbigger(stack stk, int i)
{

	while (stk->next && stk->value < i)
	{
		stk = stk->next;
	}
	return (stk->value);
}

int find_small(stack stk)
{
	int small = INT_MAX;
	int small_index;
	int i;

	i = 0;
	while (!stack_is_empty(stk))
	{
		if (small > stk->value)
		{
			small = stk->value;
			small_index = i;
		}
		stk = stk->next;
		i++;

	}
	return (small_index);
}

int	first(stack stk)
{
	return ((stk)->value);
}

int second(stack stk)
{
	return (stk->next->value);
}

int last(stack stk)
{
	return ((*tail_stack(&stk))->value);
}

Bool stack_is_sorted(stack stk)
{
	while (!stack_is_empty(stk) && stack_length(stk) > 1)
	{
		if(first(stk) > second(stk))
			return (False);
		stk = stk->next;
	}
	return (True);
}