/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:08:11 by hnait             #+#    #+#             */
/*   Updated: 2023/02/27 01:25:28 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move(t_stack *a, t_stack *b, int index)
{
	int	i;
	int	bigger;

	bigger = index_of_bigger(*a, number_by_index(*b, index));
	combine_rotate(a, b, &bigger, &index);
	i = 0;
	if (index < stack_length(*b) / 2)
		while (i++ < index)
			rotate(b, 'b');
	else
		while ((stack_length(*b) - i++) > index)
			rotate_back(b, 'b');
	i = 0;
	if (bigger < stack_length(*a) / 2)
		while (i++ < bigger)
			rotate(a, 'a');
	else
		while ((stack_length(*a) - i++) > bigger)
			rotate_back(a, 'a');
	push(a, b, 'a');
}

void	push_to_b(t_stack *a, t_stack *b)
{
	t_stack	sub;
	int		biggest_a;
	int		smallest_a;

	biggest_a = biggest_in_stack(*a);
	smallest_a = number_by_index(*a, find_small_index(*a));
	sub = lis(a);
	while (stack_length(sub) < stack_length(*a))
	{
		if (!exists_in_stack(sub, first(*a)))
		{
			push(a, b, 'b');
			if (first(*b) < number_by_index(*a,
					index_of_bigger(*a, (biggest_a + smallest_a) / 2)))
				rotate(b, 'b');
		}
		else
			rotate(a, 'a');
	}
	while (!stack_is_empty(sub))
		pop_stack(&sub);
}

void	move_small(t_stack *a, char name)
{
	int		i;
	int		small;
	int		index_of_small;
	t_stack	tmp;

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
