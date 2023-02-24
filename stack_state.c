/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:29:36 by hnait             #+#    #+#             */
/*   Updated: 2023/02/24 20:30:03 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	stack_is_empty(t_stack stk)
{
	if (stk == NULL)
		return (True);
	return (False);
}

t_bool	stack_is_sorted(t_stack stk)
{
	while (!stack_is_empty(stk) && stack_length(stk) > 1)
	{
		if (first(stk) > second(stk))
			return (False);
		stk = stk->next;
	}
	return (True);
}
