/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_from_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:50:03 by hnait             #+#    #+#             */
/*   Updated: 2023/02/24 20:50:26 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
