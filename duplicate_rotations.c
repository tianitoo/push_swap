/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_rotations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:00:21 by hnait             #+#    #+#             */
/*   Updated: 2023/02/24 17:00:22 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *a, t_stack *b)
{
	rotate(a, 'n');
	rotate(b, 'n');
	ft_printf("rr\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rotate_back(a, 'n');
	rotate_back(b, 'n');
	ft_printf("rrr\n");
}
