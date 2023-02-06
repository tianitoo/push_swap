/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:39:59 by hnait             #+#    #+#             */
/*   Updated: 2023/02/06 14:40:24 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argv, char **argc)
{
	stack stk;
	int i;
	int nbr;
	char **ss;

	i = argv - 1;
	stk = new_stack();
	if (check_double(argc) == 0)
	{
		ft_printf("ERROiR");
		return (0);
	}
	while (i > 0)
	{
		ss = split(argc[i]);
		if (!ss)
			return (0);
		
		while (*ss)
		{
			nbr = ft_atoi(*ss);
			if (nbr)
				stk = push_stack(stk, nbr);
			ss++;
		}
		i--;
	}

	// print_stack(stk);
	// stk = pop_stack(stk);
	// stk = clear_stack(stk);
	// print_stack(stk);
	// print_stack(stk);
	if(stack_length(stk) > 1 && !stack_is_sorted(stk))
		push_swap(&stk);
	// print_stack(stk);
	// print_stack(stk);
	// print_stack(stk);
	
}