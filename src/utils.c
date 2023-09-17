/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:21:59 by kchan             #+#    #+#             */
/*   Updated: 2023/09/12 14:43:37 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../libft/libft.h"

void	ft_error(char *msg)
{
	perror(msg);
	exit(-1);
}

void	ft_free_subarray(char **subarray)
{
	int	i;

	i = 0;
	if (subarray == NULL)
		return ;
	while (subarray[i] != 0)
	{
		free(subarray[i]);
		i++;
	}
	free(subarray);
}

char	**ft_get_path(char **env)
{
	char	**ptr;
	char	*ptr_tem;
	char	**path;

	ptr = env;
	while (ptr && *ptr)
	{
		if (ft_strncmp("PATH=", *ptr, 5) == 0)
		{
			ptr_tem = ft_substr(*ptr, 5, (ft_strlen(*ptr) - 5));
			path = ft_split(ptr_tem, ':');
			free(ptr_tem);
			return (path);
		}
		ptr++;
	}
	return (NULL);
}

char	*ft_get_fullpath(char *cmd, char **path)
{
	int		i;
	char	*path_tem;
	char	*exec;
	char	**split_cmd;

	i = 0;
	while (path && path[i])
	{
		split_cmd = ft_split(cmd, ' ');
		path_tem = ft_strjoin(path[i], "/");
		exec = ft_strjoin(path_tem, split_cmd[0]);
		free(split_cmd);
		free(path_tem);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
		i++;
	}
	perror("Command not found");
	return (NULL);
}
