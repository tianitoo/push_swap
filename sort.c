/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:08:11 by hnait             #+#    #+#             */
/*   Updated: 2023/02/16 14:19:30 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(stack *a, stack *b)
{
	// if (stack_length(*a) == 3)
	// 	three(a, 'a');
	// else
		more(a, b);
		// print_stack(*a);
}

// void	three(stack *stk, char stk_name)
// {
// 	while (!stack_is_sorted(*stk))
// 	{
// 		if (first(*stk) > second(*stk) && first(*stk) > last(*stk))
// 			rotate(stk, stk_name);
// 		if (second(*stk) > first(*stk) && second(*stk) > last(*stk))
// 			rotate_back(stk, stk_name);
// 		if (!stack_is_sorted(*stk))
// 			*stk = swap(*stk, stk_name);
// 	}
// }

int	number_of_instructions(stack *a, stack b, int index)
{
	int moves;
	int	index_bigger;
	index_bigger = index_of_bigger(*a, number_by_index(b, index));
	// ft_printf("index of bigger of %d : %d\n",number_by_index(*b, index), index_bigger);
	moves = 0;
	if (index < stack_length(b) / 2)
		moves += index;
	else
		moves += stack_length(b) - index;
	
	if (index_bigger <= stack_length(*a) / 2)
	{
		moves += index_bigger;
	}
	else
	{
		moves += stack_length(*a) - index_of_bigger(*a, number_by_index(b, index));
	}
	// ft_printf("number of moves %d\n", moves);
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
	int com_rotate;
	int rra;
	int rrb;
	
	bigger = index_of_bigger(*a, number_by_index(*b, index));
		com_rotate = 0;
	if (index < stack_length(*b) / 2 && bigger < stack_length(*a) / 2)
	{
		while (com_rotate < index && com_rotate < bigger)
			com_rotate++;
		index -= com_rotate;
		bigger -= com_rotate;
		while (com_rotate-- > 0)
			rr(a, b);
	}
	if ((index > stack_length(*b) / 2) && (bigger > stack_length(*a) / 2))
	{
		rra = stack_length(*a);
		rrb = stack_length(*b);
		while (rrb-- > index && rra-- > bigger)
			com_rotate++;
		index += com_rotate;
		bigger += com_rotate;
			// ft_printf("com rotate %d, index %d, bigger %d\n", com_rotate, index, bigger);
		while (com_rotate-- > 0)
		{
			rrr(a, b);
		}
	}
	i = 0;
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
	// if (*b && (*b)->next)
	// 	if (first(*b) > second(*b))
	// 		*b = swap(*b, 'b');
}

void	more(stack *a, stack *b)
{
	stack tmp_b;
	stack	sub;
	int *moves;
	int i;

	i = 0;
	sub = lis(a);
	ft_printf("sub ");
	print_stack(sub);
	while (stack_length(sub) < stack_length(*a))
	{
		if (!exists_in_stack(sub, first(*a)))
		{
			push(a, b, 'b');
		}
		else
		{
			rotate(a, 'a');
			i++;
		}
	}
	while (!stack_is_empty(*b))
	{
		print_stack(*a);
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
		print_stack(*a);
	}
	move_small(a, 'a');
	// if (stack_is_sorted(*a))
	// 	print_stack(*a);
}

stack lis(stack *stk)
{
	int	i;
	int *liste;
	int small;
	stack sub;

	if (stack_is_empty(*stk))
		return (NULL);
	sub = clone_stack(stk);
	small = number_by_index(*stk, find_small(*stk));
	
	i = 0;
	move_small(&sub, 'n');
	rotate(&sub, 'n');
	while (i < stack_length(*stk))
	{
		print_stack(sub);
		if (first(sub) == biggest_in_stack(sub))
		{
			rotate(&sub, 'n');
			while (first(sub) != number_by_index(sub, find_small(sub)))
			{
				pop_stack(&sub);
				i++;
			}
		}
		else if (first(sub) > last(sub) && first(sub) < second(sub))
		{
			rotate(&sub, 'n');
		}
		else if (last(sub) > second(sub) || last(sub) > first(sub))
		{
			rotate(&sub, 'n');
			pop_stack(&sub);
			rotate_back(&sub, 'n');
		}
		else if (first(sub) > second(sub))
		{
			pop_stack(&sub);
		}
		i++;
	}
	return (sub);
}


stack sub(stack stk)
{
	int i;
	stack substack;
	stack longest_sub;

	substack = new_stack();
	longest_sub = new_stack();
	i = 0;
	while (i < stack_length(stk))
	{
		print_stack(stk);
		pop_stack(&stk);
		if (stack_is_empty(stk))
			return (NULL);
		ft_printf("i = %d\n", i);
		if (element_by_index(stk, i) > element_by_index(stk, i - 1))
		{
			substack = sub(element_by_index(stk, i));
			if (stack_length(substack) > stack_length(longest_sub))
			{
				longest_sub = substack;
			}
		}
		i++;
	}
	return (longest_sub);
}
