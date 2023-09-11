/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:26:03 by kchan             #+#    #+#             */
/*   Updated: 2023/04/04 11:18:46 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tem_s;
	char	*buffer;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	tem_s = (char *)s;
	buffer = malloc (sizeof (char) * (ft_strlen(s)+1));
	if (!buffer)
		return (NULL);
	while (tem_s[i] != '\0')
	{
		buffer[i] = (*f)(i, tem_s[i]);
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
