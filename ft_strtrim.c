/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:16:44 by kchan             #+#    #+#             */
/*   Updated: 2023/04/04 10:53:25 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isset(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*substr;
	size_t	i;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_isset (s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_isset (s1[end - 1], set))
		end--;
	substr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i + start < end)
	{
		substr[i] = s1 [start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
