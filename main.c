/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:39:59 by hnait             #+#    #+#             */
/*   Updated: 2023/02/24 16:43:48 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*concat_argv(char **argv, int argc)
{
	int		i;
	char	*concat;
	char	*concat_space;

	i = argc - 1;
	concat = ft_calloc(2, 1);
	concat[0] = ' ';
	while (i > 0)
	{
		concat_space = ft_strjoin(concat, " ");
		free(concat);
		concat = ft_strjoin(concat_space, argv[i]);
		free(concat_space);
		i--;
	}
	return (concat);
}

void	zero_parameter(char *concat)
{
	if (sslen(concat, ' ') == 0)
	{
		ft_printf("ERROlR");
		free(concat);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stk;
	int		i;
	char	**ss;
	char	*concat;

	stk = NULL;
	concat = concat_argv(argv, argc);
	zero_parameter(concat);
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
	if (stack_length(stk) > 1 && !stack_is_sorted(stk))
		push_swap(&stk);
}
