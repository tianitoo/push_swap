/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 04:15:16 by hnait             #+#    #+#             */
/*   Updated: 2022/11/05 14:12:15 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	if (dst == src)
		return (dst);
	if (!dst && !src)
		return (0);
	i = 0;
	s = (unsigned char *) src;
	d = (unsigned char *) dst;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
