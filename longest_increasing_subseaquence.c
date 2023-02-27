/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_subseaquence.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:50:53 by hnait             #+#    #+#             */
/*   Updated: 2023/02/24 20:55:25 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
