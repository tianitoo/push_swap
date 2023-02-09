/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:08:11 by hnait             #+#    #+#             */
/*   Updated: 2023/02/09 16:42:03 by hnait            ###   ########.fr       */
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
	else
		more(a, b);
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
	int index_bigger;

	push(a, b, 'b');
	push(a, b, 'b');
	three(a, 'a');
	three(b, 'b');
	while (!stack_is_empty(*b))
	{
		index_bigger = index_of_bigger(*a, first(*b));
		while (index_bigger != first(*a))
		{
			if (index_bigger > stack_length(*a) / 2 && index_bigger != 1)
				rotate(a, 'a');
			else
				rotate_back(a, 'a');
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

int	number_of_instructions(stack *a, stack *b, int index)
{
	int moves;
	int	index_bigger;
	ft_printf("inside b : ");
	print_stack(*b);
	index_bigger = index_of_bigger(*a, number_by_index(*b, index));
	// ft_printf("index of bigger of %d : %d\n",number_by_index(*b, index), index_bigger);
	moves = 0;
	if (index < stack_length(*b) / 2)
		moves += index;
	else
		moves += stack_length(*b) - index;
	
	if (index_bigger <= stack_length(*a) / 2)
	{
		moves += index_bigger;
	}
	else
	{
		moves += stack_length(*a) - index_of_bigger(*a, number_by_index(*b, index));
	}
	// ft_printf("number of moves %d\n", moves);
	ft_printf("inside b : ");
	print_stack(*b);
	return (moves + 1);
}

int	find_small_table(int *table, int length)
{
	int small;
	int i;
	int index;

	i = 0;
	small = INT_MAX;
	while (i <length)
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

void	move(stack *a, stack *b, int index)
{
	int i;
	int bigger;
	i = 0;
	// ft_printf("%d_____________________", index);
	bigger = index_of_bigger(*a, number_by_index(*b, index));
	if (index < stack_length(*b) / 2)
	{
		while (i < index)
		{
			rotate(b, 'b');
			i++;
		}
	} else {
		while ((stack_length(*b) - i) > index)
		{
			rotate_back(b, 'b');
			i++;
		}
	}
	// ft_printf("index of bigger than %d : %d, index is %d\n", number_by_index(*b, index), bigger, index);
	i = 0;
	if (bigger < stack_length(*a) / 2)
	{
		while (i < bigger)
		{
			rotate(a, 'a');
			i++;
		}
	} else {
		while ((stack_length(*a) - i) > bigger)
		{
			rotate_back(a, 'a');
			i++;
		}
	}
	push(a, b, 'a');
}

void	more(stack *a, stack *b)
{
	stack tmp_b;
	int *moves;
	int i;

	
	moves = (int *) malloc (sizeof(int) * stack_length(*b));
	if (!moves)
		return ;
	while (stack_length(*a) > 1)
		push(a, b, 'b');
	while (!stack_is_empty(*b))
	{
		print_stack(*a);
		print_stack(*b);
		tmp_b = clone_stack(*b);
		i = 0;
		while (!stack_is_empty(tmp_b))
		{
			ft_printf("first b : ");
			print_stack(*b);
			moves[i] = number_of_instructions(a, b, i);
			ft_printf("b : ");
			print_stack(*b);
			ft_printf("tmp b : ");
			print_stack(tmp_b);
			i++;
			tmp_b = (tmp_b)->next;
		}
		print_stack(*a);
		print_stack(*b);
		move(a, b, find_small_table(moves, stack_length(*b)));
		ft_printf("\n");
	}
}