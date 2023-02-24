/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:35:14 by hnait             #+#    #+#             */
/*   Updated: 2023/02/20 05:05:23 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long long	i;
	unsigned long long	ndlen;
	unsigned long long	hslen;

	ndlen = ft_strlen(needle);
	hslen = ft_strlen(haystack);
	i = 0;
	if ((haystack == 0 && len == 0) || ndlen > len)
		return (0);
	if (ndlen == 0 || needle == haystack)
		return ((char *)haystack);
	while (*haystack != 0 && i <= len - ndlen)
	{
		if (ft_strncmp(haystack, needle, ndlen) == 0)
			return ((char *) haystack);
		i++;
		haystack++;
	}
	return (0);
}
