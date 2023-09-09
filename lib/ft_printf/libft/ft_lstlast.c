/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:49:00 by kchan             #+#    #+#             */
/*   Updated: 2023/04/04 15:15:48 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;

	i = ft_lstsize(lst);
	if (!lst)
		return (NULL);
	while (i >= 0)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
		i--;
	}
	return (lst);
}
