/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsignedint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:03:13 by kchan             #+#    #+#             */
/*   Updated: 2023/05/02 14:21:59 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	p_itoa_unsigned_decimal(unsigned int nb)
{
	if (nb > 9)
	{
		p_itoa_unsigned_decimal((nb / 10));
		p_itoa_unsigned_decimal((nb % 10));
	}
	else
	{
		ft_putchar_fd(nb + '0', 1);
	}
}

void	ft_print_unsignedint(t_print *tab)
{
	unsigned int	nbr;
	unsigned int	tem;
	int				addrlen;

	nbr = va_arg(tab->args, unsigned int);
	tem = nbr;
	addrlen = 0;
	if (!tem)
	{
		addrlen += 1;
	}
	while (tem > 0)
	{
		tem /= 10;
		addrlen++;
	}
	p_itoa_unsigned_decimal(nbr);
	(*tab).tl += addrlen;
}
