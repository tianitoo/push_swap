/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:08:24 by hnait             #+#    #+#             */
/*   Updated: 2023/02/27 03:33:14 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*push_swap(t_stack *a)
{
	t_stack	b;

	b = NULL;
	sort(a, &b);
	return (a);
}

void	sort(t_stack *a, t_stack *b)
{
	if (stack_length(*a) <= 3)
		three(a, 'a');
	else if (stack_length(*a) <= 5)
		five(a, b);
	else
		more(a, b);
}

void	three(t_stack *stk, char stk_name)
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

void	five(t_stack *a, t_stack *b)
{
	move_small(a, 'a');
	push(a, b, 'b');
	push(a, b, 'b');
	three(a, 'a');
	move(a, b, 0);
	move(a, b, 1);
}

void	more(t_stack *a, t_stack *b)
{
	t_stack	tmp_b;
	int		*moves;
	int		i;

	push_to_b(a, b);
	while (!stack_is_empty(*b))
	{
		moves = (int *) malloc (sizeof(int) * stack_length(*b));
		if (!moves)
			return ;
		tmp_b = clone_stack(b);
		i = 0;
		while (!stack_is_empty(tmp_b))
		{
			moves[i] = number_of_instructions(a, *b, i);
			i++;
			tmp_b = next(tmp_b);
		}
		move(a, b, find_small_table(moves, stack_length(*b)));
		free(moves);
	}
	move_small(a, 'a');
}
