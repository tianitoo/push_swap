/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:59:29 by hnait             #+#    #+#             */
/*   Updated: 2023/02/24 20:33:26 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, char stk)
{
	t_element	*e;

	e = NULL;
	if (stack_is_empty(*stack) || stack_length(*stack) == 1)
		return ;
	e = push_stack(e, first(*stack));
	pop_stack(stack);
	(*tail_stack(stack))->next = e;
	if (stk != 'n')
		ft_printf("r%c\n", stk);
}

void	rotate_back(t_stack *a, char stk)
{
	int		e;
	t_stack	*pop;

	e = (*tail_stack(a))->value;
	pop = tail_stack(a);
	pop_stack(pop);
	*a = push_stack(*a, e);
	if (stk != 'n')
		ft_printf("rr%c\n", stk);
}
