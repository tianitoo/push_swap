/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 03:20:42 by hnait             #+#    #+#             */
/*   Updated: 2023/02/27 03:24:28 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_stack stk, int i)
{
	if (exists_in_stack(stk, i))
		return (1);
	return (0);
}

void	end(char *concat, char **ss, int error, t_stack *stk)
{
	if (concat)
		free(concat);
	if (ss && *ss)
		free_ss(ss);
	if (error)
		ft_printf("error\n");
	while (!stack_is_empty(*stk))
		pop_stack(stk);
	exit(0);
}

t_bool	check_arg(char *arg)
{
	size_t	i;
	char	*trimed_arg;

	i = 0;
	trimed_arg = ft_strtrim(arg, " ");
	if (ft_strlen(trimed_arg) == 0)
		return (free(trimed_arg), False);
	free(trimed_arg);
	while (i < ft_strlen(arg))
	{
		if (arg[i] == '+' || arg[i] == '-')
		{
			if ((i != 0 && arg[i - 1] != ' ')
				|| !ft_isdigit(arg[i + 1]))
				return (False);
		}
		else if (!ft_isdigit(arg[i]) && arg[i] != ' ')
		{
			return (False);
		}
		i++;
	}
	return (True);
}

char	*concat_args(int argc, char **argv)
{
	char	*concat;
	char	*concat_space;
	int		i;

	concat = ft_strdup(" ");
	i = 1;
	while (i < argc)
	{
		if (!check_arg(argv[i]))
			end(concat, NULL, 1, NULL);
		concat_space = ft_strjoin(concat, " ");
		free(concat);
		concat = ft_strjoin(concat_space, argv[i]);
		free(concat_space);
		i++;
	}
	return (concat);
}

char	*fix_zero(char *str)
{
	char	*holder;

	while (ft_strlen(str) > 1 &&
		str[0] == '0' && (str[1] == '0' || str[1] != '0'))
	{
		holder = ft_strdup(&str[1]);
		free(str);
		str = holder;
	}
	return (str);
}
