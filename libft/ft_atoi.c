/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 03:13:47 by hnait             #+#    #+#             */
/*   Updated: 2023/03/14 09:42:10 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char c)
{
	if (
		c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
	)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	nbr;
	int			signe;

	nbr = 0;
	signe = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			signe *= -1;
	}
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str++ - '0');
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (0);
	}
	nbr = nbr * signe;
	return (nbr);
}
