/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:48:04 by kchan             #+#    #+#             */
/*   Updated: 2023/04/04 10:55:21 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d_ptr;
	const char	*s_ptr;

	d_ptr = (char *)dst;
	s_ptr = (const char *)src;
	if (!src && !dst)
	{
		return (0);
	}
	while (n--)
	{
		*d_ptr++ = *s_ptr++;
	}
	return (dst);
}
