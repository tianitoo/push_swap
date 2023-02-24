/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:08:24 by hnait             #+#    #+#             */
/*   Updated: 2023/02/24 15:50:08 by hnait            ###   ########.fr       */
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

int	check_double(t_stack stk, int i)
{
	if (exists_in_stack(stk, i))
		return (1);
	return (0);
}
