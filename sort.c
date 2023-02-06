/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:08:11 by hnait             #+#    #+#             */
/*   Updated: 2023/02/06 14:11:53 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(stack *a, stack *b)
{
	if (stack_length(*a) <= 3)
		three(a, 'a');
	else if (stack_length(*a) <= 5)
		five(a, b);

	// else if (stack_length(*a) <= 100)
	// 	hundred(*a, *b);
	// else if (stack_length(*a) > 100)
	// 	more(*a, *b);
}

void	three(stack *stk, char stk_name)
{
	while (!stack_is_sorted(*stk))
	{
		if (first(*stk) > second(*stk) && first(*stk) > last(*stk))
			rotate(stk, stk_name);
		if (second(*stk) > first(*stk) && second(*stk) > last(*stk))
			rotate_back(stk, stk_name);
		if (!stack_is_sorted(*stk))
			*stk = swap(*stk, stk_name);
	}
}

void	five(stack *a, stack *b)
{
	int bigger;

	push(a, b, 'b');
	push(a, b, 'b');
	three(a, 'a');
	three(b, 'b');
	while (!stack_is_empty(*b))
	{
		bigger = isbigger(*a, first(*b));
		while (bigger != first(*a))
		{
			if (bigger > stack_length(*a) / 2 && bigger != 1)
				rotate(a, 'a');
			else
				rotate_back(a,'a');
		}
		if (first(*a) < first(*b))
			rotate(a, 'a');
		push(a, b, 'a');
	}
	while (!stack_is_sorted(*a))
		if (find_small(*a) < stack_length(*a) / 2)
			move_small(a, find_small(*a), 'a', rotate_back);
		else
			move_small(a, find_small(*a), 'a', rotate);
}