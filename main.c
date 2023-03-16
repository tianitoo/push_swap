/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:39:59 by hnait             #+#    #+#             */
/*   Updated: 2023/03/16 21:43:43 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	char	*concat;
	char	**ss;
	t_stack	stk;

	ss = NULL;
	stk = NULL;
	concat = concat_args(argc, argv);
	ss = ft_split(concat, ' ');
	i = sslen(concat, ' ') - 1;
	while (i >= 0)
	{
		ss[i] = fix_zero(ss[i]);
		if (!check_arg(ss[i]) || check_double(stk, ft_atoi(ss[i]))
			|| (((ss[i][0] != '+' || ss[i][0] != '-') && ss[i][1] != '0')
			&& ft_atoi(ss[i]) == 0))
			end(concat, ss, 1, &stk);
		stk = push_stack(stk, ft_atoi(ss[i]));
		i--;
	}
	push_swap(&stk);
	end(concat, ss, 0, &stk);
	return (0);
}
