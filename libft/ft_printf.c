/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:53:09 by kchan             #+#    #+#             */
/*   Updated: 2023/05/02 15:57:18 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_eval_format(t_print *tab, const char *format, int pos)
{
	if (format[pos] == 'c')
		ft_print_c(tab);
	else if (format[pos] == 's')
		ft_print_s(tab);
	else if (format[pos] == 'p')
		ft_print_p(tab);
	else if (format[pos] == 'd' || format[pos] == 'i')
		ft_print_di(tab);
	else if (format[pos] == 'u')
		ft_print_unsignedint(tab);
	else if (format[pos] == 'x')
		ft_print_hex(tab, 32);
	else if (format[pos] == 'X')
		ft_print_hex(tab, 0);
	else if (format[pos] == '%')
		ft_print_percentage(tab);
	else
		return ;
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	t_print	*tab;

	tab = ft_calloc(1, sizeof(t_print));
	if (!tab)
		return (-1);
	va_start((*tab).args, format);
	i = -1;
	ret = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i += 1;
			ft_eval_format(tab, format, i);
		}
		else
			ret += write(1, &format[i], 1);
	}
	va_end((*tab).args);
	ret += (*tab).tl;
	free (tab);
	return (ret);
}
