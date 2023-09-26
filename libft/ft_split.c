/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:26:01 by lnambaji          #+#    #+#             */
/*   Updated: 2023/04/04 10:55:46 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countsplit(char const *s, char c)
{
	size_t	n;
	size_t	index;

	n = 0;
	index = 0;
	while (s && s[index])
	{
		if (s[index] != c)
		{
			n++;
			while (s[index] != c && s[index])
			{
				index++;
			}
		}
		else
			index++;
	}
	return (n);
}

size_t	ft_strlen_delimited(char const *s, char c, size_t i)
{
	int	size;

	size = 0;
	while (s[i] && s[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

void	freearr(char **str, int j)
{
	while (j-- > 0 && str && str[j])
	{
		free (str[j]);
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	char		**new_str;

	i = 0;
	j = -1;
	if (!s)
		return (0);
	new_str = (char **)malloc(sizeof (char *) * (ft_countsplit(s, c) + 1));
	if (!new_str)
		return (0);
	new_str[ft_countsplit(s, c)] = 0;
	while (++j < ft_countsplit(s, c))
	{
		while (s[i] == c)
			i++;
		new_str[j] = ft_substr(s, i, ft_strlen_delimited(s, c, i));
		if (!new_str[j])
		{
			freearr(new_str, j);
			return (0);
		}
		i += ft_strlen_delimited(s, c, i);
	}
	return (new_str);
}
