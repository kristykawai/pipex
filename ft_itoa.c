/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:45:54 by kchan             #+#    #+#             */
/*   Updated: 2023/09/26 15:34:36 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_number(long n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	i;

	i = n;
	len = ft_len_number(i);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len = len - 1;
	if (i == 0)
		str[0] = '0';
	if (i < 0)
	{
		i = i * -1;
		str[0] = '-';
	}
	while (i > 0)
	{
		str[len] = '0' + (i % 10);
		len --;
		i /= 10;
	}
	return (str);
}
