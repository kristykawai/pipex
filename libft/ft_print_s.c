/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:03:36 by kchan             #+#    #+#             */
/*   Updated: 2023/05/02 14:21:56 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_s(t_print *tab)
{
	char	*tem;
	char	*str;
	int		len;

	tem = va_arg (tab->args, char *);
	if (tem == NULL)
	{
		str = ft_strdup("(null)");
		if (!str)
			return ;
	}
	else
	{
		str = tem;
	}
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	tab->tl += len;
	if (tem == NULL || tem != str)
		free(str);
}
