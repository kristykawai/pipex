/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:50:27 by kchan             #+#    #+#             */
/*   Updated: 2023/04/04 10:56:10 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*s;
	size_t	len_dst;
	size_t	len_src;
	size_t	len_total;
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	s = (char *) src;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(s);
	len_total = 0;
	i = 0;
	if (dstsize > len_dst)
		len_total = len_src + len_dst;
	else
		len_total = len_src + dstsize;
	while ((len_dst < dstsize -1) && s[i] != '\0')
	{
		dst[len_dst] = s[i];
		len_dst++;
		i++;
	}
	dst[len_dst] = '\0';
	return (len_total);
}
