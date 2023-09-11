/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:31:42 by kchan             #+#    #+#             */
/*   Updated: 2023/05/02 15:56:16 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	p_itoa_hex(unsigned int nb, int x)
{
	if (nb > 15)
	{
		p_itoa_hex((nb / 16), x);
		p_itoa_hex((nb % 16), x);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd(nb + '0', 1);
		else
			ft_putchar_fd(nb - 10 + 'A' + x, 1);
	}
}

void	ft_print_hex(t_print *tab, int x)
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
		tem /= 16;
		addrlen++;
	}
	p_itoa_hex(nbr, x);
	(*tab).tl += addrlen;
}
