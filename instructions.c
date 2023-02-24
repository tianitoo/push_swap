/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 04:47:42 by hnait             #+#    #+#             */
/*   Updated: 2023/02/24 20:32:58 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *a, t_stack *b, char stk)
{
	if (stk == 'a')
	{
		if (stack_is_empty(*b))
			return ;
		*a = push_stack(*a, (*b)->value);
		pop_stack(b);
		ft_printf("pa\n");
	}
	else if (stk == 'b')
	{
		if (stack_is_empty(*a))
			return ;
		*b = push_stack(*b, (*a)->value);
		pop_stack(a);
		ft_printf("pb\n");
	}
}

t_stack	swap(t_stack stk, char name)
{
	int	a;
	int	b;

	a = first(stk);
	pop_stack(&stk);
	b = first(stk);
	pop_stack(&stk);
	stk = push_stack(stk, a);
	stk = push_stack(stk, b);
	if (stk != 0)
		ft_printf("s%c\n", name);
	return (stk);
}
