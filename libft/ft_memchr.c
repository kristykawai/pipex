/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:44:30 by kchan             #+#    #+#             */
/*   Updated: 2023/04/04 10:55:09 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*p = s;

	i = 0;
	while (i < n)
	{
		if (*p == (unsigned char)c)
		{
			return ((void *)(p));
		}
		i++;
		p++;
	}
	return (NULL);
}
