/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:50:05 by kchan             #+#    #+#             */
/*   Updated: 2023/04/04 10:55:54 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*new_str;

	len = ft_strlen(s1);
	new_str = malloc(len + 1);
	if (new_str != NULL)
	{
		ft_memcpy(new_str, s1, len + 1);
	}
	return (new_str);
}
