/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:54:03 by kchan             #+#    #+#             */
/*   Updated: 2023/09/26 15:34:10 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*str;

	i = 0;
	str = s;
	while (s[i] != '\0')
	{
		str++;
		i++;
	}
	while (i >= 0)
	{
		if ((unsigned char)*str == (unsigned char)c)
		{
			return ((char *)(str));
		}
		str--;
		i--;
	}
	return (NULL);
}
