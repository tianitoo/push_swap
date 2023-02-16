/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:39:59 by hnait             #+#    #+#             */
/*   Updated: 2023/02/16 13:51:21 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	stack stk;
	int i;
	int j;
	int nbr;
	char **ss;
	char *concat;

	i = argc -1;
	concat = " ";
	stk = new_stack();
	while (i > 0)
	{
		concat = ft_strjoin(concat, " ");
		concat = ft_strjoin(concat, argv[i]);
		i--;
	}
	ss = ft_split(concat, ' ');
	i = 0;
	while (i < sslen(concat, ' '))
	{
		if ((ft_strncmp(ss[i], "0", 1) == 0 || ft_atoi(ss[i]) != 0)
				&& (check_double(stk, ft_atoi(ss[i])) == 0))
			stk = push_stack(stk, ft_atoi(ss[i]));
		else
		{
			ft_printf("ERROiR");
			return (0);
		}
		i++;
	}
	
	print_stack(stk);
	print_stack(sub(stk));
	
	// if(stack_length(stk) > 1 && !stack_is_sorted(stk))
	// 	push_swap(&stk);
	// print_stack(stk);
}