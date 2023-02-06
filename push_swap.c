/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:08:24 by hnait             #+#    #+#             */
/*   Updated: 2023/02/06 14:39:44 by hnait            ###   ########.fr       */
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
	return (a);
}

void move_small(stack *a,
				int index,
				char name,
				void (*rotate)(stack *a,
				char stk_name))
{
	int i;

	i = 0;
	while (i < index)
	{
		(*rotate)(a, name);
		i++;
	}
}

int check_double(char **ss)
{
	int i;
	int j;

	i = 1;
	while (ss[i])
	{
		j = i + 1;
		while (ss[j])
		{
			if ((ft_strncmp(ss[i], ss[j], ft_strlen(ss[i])) == 0) 
					&& ft_strlen(ss[i]) == ft_strlen(ss[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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
