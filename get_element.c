/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:23:31 by hnait             #+#    #+#             */
/*   Updated: 2023/02/24 20:25:01 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	push_stack(t_stack stk, int i)
{
	t_element	*e;

	e = malloc(sizeof(*e));
	if (e == NULL)
		return (NULL);
	e->value = i;
	e->next = stk;
	return (e);
}

t_stack	*tail_stack(t_stack *stk)
{
	t_stack	*tail;

	tail = stk;
	if (stack_is_empty(*tail))
		return (tail);
	while (!stack_is_empty((*tail)->next))
		tail = &(*tail)->next;
	return (tail);
}

t_stack	next(t_stack stk)
{
	t_stack	e;

	e = stk;
	stk = stk->next;
	free(e);
	return (stk);
}

t_stack	element_by_index(t_stack stk, int index)
{
	int	i;

	i = 0;
	if (stack_is_empty(stk))
		return (NULL);
	while (i < index)
	{
		stk = (stk)->next;
		i++;
	}
	return (stk);
}
