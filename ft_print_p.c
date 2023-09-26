/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:49:43 by kchan             #+#    #+#             */
/*   Updated: 2023/05/02 14:21:49 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	p_itoa_hex(size_t nb)
{
	if (nb > 15)
	{
		p_itoa_hex((nb / 16));
		p_itoa_hex((nb % 16));
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd(nb + '0', 1);
		else
			ft_putchar_fd(nb - 10 + 'a', 1);
	}
}

void	ft_print_p(t_print *tab)
{
	size_t	tem;
	size_t	ptr;
	int		addrlen;

	ptr = va_arg(tab->args, size_t);
	if (!ptr)
	{
		ft_putstr_fd("0x0", 1);
		(*tab).tl += 3;
		return ;
	}
	tem = ptr;
	addrlen = 2;
	while (tem > 0)
	{
		tem /= 16;
		addrlen++;
	}
	write (1, "0x", 2);
	p_itoa_hex(ptr);
	(*tab).tl += addrlen;
}
