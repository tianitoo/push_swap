/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_number_of_instructions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:49:58 by hnait             #+#    #+#             */
/*   Updated: 2023/02/24 20:49:59 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_of_instructions(t_stack *a, t_stack b, int index)
{
	int	moves;
	int	index_bigger;

	index_bigger = index_of_bigger(*a, number_by_index(b, index));
	moves = 0;
	if (index < stack_length(b) / 2)
		moves += index;
	else
		moves += stack_length(b) - index;
	if (index_bigger <= stack_length(*a) / 2)
		moves += index_bigger;
	else
		moves += stack_length(*a) - index_bigger;
	return (moves + 1);
}

void	combine_rotate(t_stack *a, t_stack *b, int *bigger, int *index)
{
	int	com_rotate;
	int	rra;
	int	rrb;

	com_rotate = 0;
	if (*index < stack_length(*b) / 2 && *bigger < stack_length(*a) / 2)
	{
		while (com_rotate < *index && com_rotate < *bigger)
			com_rotate++;
		*index -= com_rotate;
		*bigger -= com_rotate;
		while (com_rotate-- > 0)
			rr(a, b);
	}
	if ((*index > stack_length(*b) / 2) && (*bigger > stack_length(*a) / 2))
	{
		rra = stack_length(*a);
		rrb = stack_length(*b);
		while (rrb-- > *index && rra-- > *bigger)
			com_rotate++;
		*index += com_rotate;
		*bigger += com_rotate;
		while (com_rotate-- > 0)
			rrr(a, b);
	}
}
