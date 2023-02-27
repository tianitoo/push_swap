/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:08:53 by hnait             #+#    #+#             */
/*   Updated: 2023/02/26 23:22:03 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack stk)
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

void	pop_stack(t_stack *stk)
{
	t_element	*e;

	if (stack_is_empty(*stk))
		return ;
	e = (*stk)->next;
	free(*stk);
	*stk = NULL;
	*stk = e;
}

int	stack_length(t_stack stk)
{
	int	length;

	length = 0;
	while (!stack_is_empty(stk))
	{
		length++;
		stk = stk->next;
	}
	return (length);
}

t_stack	clone_stack(t_stack *stk)
{
	t_stack	clone;
	int		i;

	clone = NULL;
	i = 0;
	while (i < stack_length(*stk))
	{
		clone = push_stack(clone, last(*stk));
		rotate_back(stk, 'n');
		i++;
	}
	return (clone);
}

t_bool	exists_in_stack(t_stack stk, int number)
{
	while (stk)
	{
		if (number == stk->value)
			return (True);
		stk = stk->next;
	}
	return (False);
}
