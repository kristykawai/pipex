/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:08:44 by kchan             #+#    #+#             */
/*   Updated: 2023/04/04 10:55:24 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char			*d_ptr;
	const char		*s_ptr;

	d_ptr = (char *) dst;
	s_ptr = (const char *) src;
	if (d_ptr == s_ptr)
	{
		return (dst);
	}
	else if (d_ptr > s_ptr && d_ptr <= s_ptr + n)
	{
		d_ptr = d_ptr + n;
		s_ptr = s_ptr + n;
		while (n--)
			*--d_ptr = *--s_ptr;
	}
	else
	{
		while (n--)
			*d_ptr++ = *s_ptr++;
	}
	return (dst);
}
