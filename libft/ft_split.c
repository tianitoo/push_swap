/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:33:36 by hnait             #+#    #+#             */
/*   Updated: 2022/11/12 14:01:07 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	sslen(const char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (*s == '\0')
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			len++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (len);
}

static void	free_ss(char **ss)
{
	while (*ss)
	{
		free(*ss);
		ss++;
	}
	free(ss);
}

static int	next_sep(const char *s, int j, char c)
{
	while (s[j] != c && s[j])
		j++;
	return (j);
}

static char	*cut_word(const char *s, int *j, char c)
{
	char	*word;
	int		next;

	next = next_sep(s, *j, c);
	word = ft_substr(s, *j, next - *j);
	if (!(word))
		return (0);
	*j = next;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**ss;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	ss = (char **) malloc (sizeof(char *) * (sslen(s, c) + 1));
	if (!ss)
		return (0);
	while (s[j] != 0)
	{
		if (s[j] == c)
			j++;
		else
		{
			ss[i] = cut_word(s, &j, c);
			if (!ss[i])
				return (free_ss(ss), NULL);
			i++;
		}
	}
	ss[i] = NULL;
	return (ss);
}
