/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 04:58:18 by hnait             #+#    #+#             */
/*   Updated: 2022/11/11 18:56:40 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;
	char	*r;

	p = (char *)s;
	i = 0;
	r = 0;
	if ((char) c == '\0')
	{
		while (p[i] != '\0')
			i++;
		return (&p[i]);
	}
	while (p[i] != '\0')
	{
		if (p[i] == (char) c)
			r = &p[i];
		i++;
	}
	return (r);
}
