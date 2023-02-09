/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:13:05 by marvin            #+#    #+#             */
/*   Updated: 2023/02/07 11:12:05 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
		ss = (char *) malloc (sizeof(char) * (len + 1));
	if (!ss)
		return (0);
	while (i < len && start < ft_strlen(s) && s[i + start])
	{
		ss[i] = s[start + i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
 