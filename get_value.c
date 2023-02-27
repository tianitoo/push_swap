/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:17:17 by hnait             #+#    #+#             */
/*   Updated: 2023/02/27 01:12:49 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first(t_stack stk)
{
	return ((stk)->value);
}

int	second(t_stack stk)
{
	return (stk->next->value);
}

int	last(t_stack stk)
{
	return ((*tail_stack(&stk))->value);
}

int	number_by_index(t_stack stk, int index)
{
	int	i;

	i = 0;
	while (i < index && stk->next)
	{
		stk = stk->next;
		i++;
	}
	return (stk->value);
}

int	biggest_in_stack(t_stack stk)
{
	int	big;

	big = INT_MIN;
	while (!stack_is_empty(stk))
	{
		if (stk->value > big)
			big = stk->value;
		stk = stk->next;
	}
	return (big);
}
