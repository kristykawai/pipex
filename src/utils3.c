/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:56:33 by kchan             #+#    #+#             */
/*   Updated: 2023/09/26 13:26:58 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../libft/libft.h"

int	check_cmd_quotes(char **cmd_parms)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (cmd_parms [1][i] != '\0')
	{
		if (cmd_parms[1][i] == '\'' || cmd_parms[1][i] == '\"')
			count++;
		i++;
	}
	return (count);
}
