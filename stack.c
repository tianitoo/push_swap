/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:08:53 by hnait             #+#    #+#             */
/*   Updated: 2023/02/16 14:04:54 by hnait            ###   ########.fr       */
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
	if (!stack_is_empty(stk))
	{
		while (!stack_is_empty(stk))
		{
			ft_printf("%d ", stk->value);
			stk = stk->next;
		}
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

void	clear_stack(stack *stk)
{
	while (!stack_is_empty(*stk))
		pop_stack(stk);
}

int index_of_bigger(stack stk, int number)
{
	int bigger_in_stk;
	int index_of_bigger;
	int i;
	int small;
	int index_of_small;

	i = 0;
	bigger_in_stk = INT_MAX;
	small = INT_MAX;
	index_of_bigger = -1;
	index_of_small = -1;
	if (stack_is_empty(stk))
		return (0);
	while (stk)
	{
		if (stk->value < small)
		{
			index_of_small = i;
			small = stk->value;
		}
		if (stk->value > number && stk->value < bigger_in_stk)
		{
			
			index_of_bigger = i;
			bigger_in_stk = stk->value;
			// ft_printf("lol %d, bigger %d\n", number, bigger_in_stk);
			// ft_printf("just bigger : %d\n", number);
		}
		i++;
		stk = stk->next;
	}
	if (index_of_bigger == -1)
		return (index_of_small);
	return (index_of_bigger);
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

int	number_by_index(stack stk, int index)
{
	int i;

	i = 0;
	while (i < index && stk->next)
	{
		stk = stk->next;
		i++;
	}
	return (stk->value);
}

Bool	stack_is_sorted(stack stk)
{
	while (!stack_is_empty(stk) && stack_length(stk) > 1)
	{
		if(first(stk) > second(stk))
			return (False);
		stk = stk->next;
	}
	return (True);
}

stack	clone_stack(stack *stk)
{
	stack clone;
	int i;

	clone = new_stack();
	i = 0;
	while (i < stack_length(*stk))
	{
		clone = push_stack(clone, last(*stk));
		rotate_back(stk, 'n');
		i++;
	}
	return (clone);
}

stack	next(stack stk)
{
	stack e;
	
	e = stk;
	stk = stk->next;
	free(e);
	return (stk);
}

int biggest_in_stack(stack stk)
{
	int big;
	big = INT_MIN;
	while (!stack_is_empty(stk))
	{
		if (stk->value > big)
			big = stk->value;
		stk = stk->next;
	}
	return (big);
}

void move_small(stack *a, char name)
{
	int i;
	int	small;
	int index_of_small;
	stack tmp;

	small = INT_MAX;
	tmp = *a;
	i = 0;
	index_of_small = 0;
	while (tmp)
	{
		if (tmp->value < small)
		{
			small = tmp->value;
			index_of_small = i;
		}
		i++;
		tmp = tmp->next;
	}
	if (index_of_small < stack_length(*a) / 2)
		while (index_of_small-- > 0)
			rotate(a, name);
	else
		while (index_of_small++ < stack_length(*a))
			rotate_back(a, name);
}

stack element_by_index(stack stk, int index)
{
	int i;

	i = 0;
	if (index < 0)
		return (0);
	if (stack_is_empty(stk))
		return (NULL);
	while (i < index)
	{
		stk = (stk)->next;
		i++;
	}
	return (stk);
}

Bool exists_in_stack(stack stk, int number)
{
	while (stk)
	{
		if (number == stk->value)
				return (True);
		stk = stk->next;
	}
	return (False);
}