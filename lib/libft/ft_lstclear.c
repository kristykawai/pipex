/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:31:07 by kchan             #+#    #+#             */
/*   Updated: 2023/04/04 15:15:37 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tem_lst;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		tem_lst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tem_lst;
	}
	*lst = NULL;
}
