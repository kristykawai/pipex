/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:53:59 by kchan             #+#    #+#             */
/*   Updated: 2023/04/04 10:56:36 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	i;
	size_t	j;

	if (!need[0])
		return ((char *) hay);
	i = 0;
	while (i < len && hay[i])
	{
		j = 0;
		while (hay[i + j] == need[j]
			&& need[j]
			&& i + j < len)
		{
			if (need[j + 1] == '\0')
				return ((char *)hay + i);
			j++;
		}
		i++;
	}
	return (0);
}
