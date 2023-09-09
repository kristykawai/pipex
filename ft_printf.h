/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:59:37 by kchan             #+#    #+#             */
/*   Updated: 2023/05/02 15:55:47 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_print
{
	va_list	args;
	int		tl;
}					t_print;

int		ft_printf(const char *format, ...);
void	ft_print_c(t_print *tab);
void	ft_print_s(t_print *tab);
void	ft_print_p(t_print *tab);
void	ft_print_di(t_print *tab);
void	ft_print_unsignedint(t_print *tab);
void	ft_print_hex(t_print *tab, int x);
void	ft_print_percentage(t_print	*tab);
#endif
