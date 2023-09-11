/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:03:20 by kchan             #+#    #+#             */
/*   Updated: 2023/05/02 15:23:50 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	p_itoa_dec(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		p_itoa_dec((nb / 10));
		p_itoa_dec((nb % 10));
	}
	else
	{
		ft_putchar_fd(nb + '0', 1);
	}
}

void	ft_print_di(t_print *tab)
{
	int	nbr;
	int	tem;
	int	addrlen;

	nbr = va_arg(tab->args, int);
	tem = nbr;
	addrlen = 0;
	if (!tem)
		addrlen += 1;
	else if (tem == -2147483648)
		addrlen += 11;
	else
		addrlen = ft_len_number(tem);
	p_itoa_dec(nbr);
	(*tab).tl += addrlen;
}
