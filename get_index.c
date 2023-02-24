/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:26:34 by hnait             #+#    #+#             */
/*   Updated: 2023/02/24 20:34:00 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_of_bigger(t_stack stk, int number)
{
	int	bigger_in_stk;
	int	index_of_bigger;
	int	i;
	int	index_of_small;

	i = 0;
	bigger_in_stk = INT_MAX;
	index_of_bigger = -1;
	index_of_small = find_small_index(stk);
	if (stack_is_empty(stk))
		return (0);
	while (stk)
	{
		if (stk->value > number && stk->value < bigger_in_stk)
		{
			index_of_bigger = i;
			bigger_in_stk = stk->value;
		}
		i++;
		stk = stk->next;
	}
	if (index_of_bigger == -1)
		return (index_of_small);
	return (index_of_bigger);
}

int	find_small_index(t_stack stk)
{
	int	small;
	int	small_index;
	int	i;

	small = INT_MAX;
	i = 0;
	if (stack_is_empty(stk))
		return (0);
	while (stk)
	{
		if (stk->value < small)
		{
			small_index = i;
			small = stk->value;
		}
		i++;
		stk = stk->next;
	}
	return (small_index);
}
