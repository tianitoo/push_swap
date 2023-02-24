/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:08:11 by hnait             #+#    #+#             */
/*   Updated: 2023/02/24 20:27:20 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_small_table(int *table, int length)
{
	int	small;
	int	i;
	int	index;

	i = 0;
	small = INT_MAX;
	while (i < length)
	{
		if (table[i] < small)
		{
			small = table[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	find_big_table(int *table, int length)
{
	int	big;
	int	i;
	int	index;

	i = 0;
	big = INT_MIN;
	while (i < length)
	{
		if (table[i] > big)
		{
			big = table[i];
			index = i;
		}
		i++;
	}
	return (index);
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

	sub = lis(a);
	while (stack_length(sub) < stack_length(*a))
	{
		if (!exists_in_stack(sub, first(*a)))
		{
			push(a, b, 'b');
			if (first(*b) < number_by_index(*a, index_of_bigger(*a,
						(biggest_in_stack(*a) + number_by_index(*a,
								find_small_index(*a))) / 2)))
				rotate(b, 'b');
		}
		else
			rotate(a, 'a');
	}
	while (!stack_is_empty(sub))
		pop_stack(&sub);
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

int	*init_pre(int *number_of_pre, t_stack *stk)
{
	int	i;

	i = 0;
	number_of_pre = (int *) ft_calloc (stack_length(*stk), sizeof(int));
	while (i < stack_length(*stk))
	{
		number_of_pre[i] = -1;
		i++;
	}
	return (number_of_pre);
}

void	find_pres(t_stack *stk, int **index, int **number_of_pre)
{
	int	i;
	int	j;
	int	pre;

	i = 1;
	while (i < stack_length(*stk))
	{
		pre = -1;
		j = 0;
		while (j < i)
		{
			if (number_by_index(*stk, j) < number_by_index(*stk, i)
				&& pre < index[0][j])
			{
				pre = index[0][j];
				index[0][i] = index[0][j] + 1;
				number_of_pre[0][i] = j;
			}
			j++;
		}
		i++;
	}
}

t_stack	lis(t_stack *stk)
{
	int		*index;
	int		*number_of_pre;
	int		i;
	t_stack	lis;

	lis = NULL;
	number_of_pre = NULL;
	number_of_pre = init_pre(number_of_pre, stk);
	index = (int *) ft_calloc (stack_length(*stk), sizeof(int));
	find_pres(stk, &index, &number_of_pre);
	i = find_big_table(number_of_pre, stack_length(*stk));
	while (i != -1)
	{
		lis = push_stack(lis, number_by_index(*stk, i));
		i = number_of_pre[i];
	}
	free(index);
	free(number_of_pre);
	return (lis);
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
