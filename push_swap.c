/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:08:24 by hnait             #+#    #+#             */
/*   Updated: 2023/02/12 15:23:26 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack *push_swap(stack *a)
{
	stack b;
	int length_a;

	length_a = stack_length(*a);
	b = new_stack();
	sort(a, &b);
	// print_stack(*a);
	return (a);
}



int check_double(stack stk, int i)
{
	if (exists_in_stack(stk, i))
		return (1);
	return (0);
}

char **split(char *s)
{
	int i;
	char **ss;
	size_t	j;

	i = 0;
	ss = ft_split(s, ' ');
	while (ss[i])
	{
		j = 0;
		while (ss[i][j])
		{
			if (!ft_isdigit(ss[i][j]))
			{
				ft_printf("ERRO6R");
				return (0);
			}
			j++;
		}
		// ft_printf("|%s|\n", ss[i]);
		if (ft_strlen(ss[i]) != j)
		{
			ft_printf("ERROoR");
			return (0);
		}
		i++;
		
	}
			// ft_printf("test\n");
	return (ss);
}
