/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:54:16 by kchan             #+#    #+#             */
/*   Updated: 2023/04/04 10:56:51 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (len + start > ft_strlen(s))
	{
		len = ft_strlen(s) - start;
	}
	cpy = (char *)malloc((sizeof (char)) * (len + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (s[start] && (i < len))
	{
		cpy[i++] = s[start++];
	}
	cpy[i] = '\0';
	return (cpy);
}
