/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:21:59 by kchan             #+#    #+#             */
/*   Updated: 2023/08/22 17:52:09 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../lib/ft_printf/libft/libft.h"

void	ft_error(char *msg)
{
	perror(msg);
	exit(-1);
}

int	ft_execute(char *cmd, char **paths, int fd_in, int fd_out)
{
	char	**cmd_parms;
	char	*cmd_path;
	int		exec_return;
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		cmd_parms = ft_split(cmd, ' ');
		cmd_path = ft_get_fullpath(cmd, paths);
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		exec_return = execve(cmd_path, cmd_parms, NULL);
		ft_free_subarray(cmd_parms);
		free(cmd_path);
		exit(exec_return);
	}
	else
    	if (wait(&status)== -1)
		perror("wait()error");
	return (status);
}

void ft_free_subarray(char **subarray) 
{
    int i;

	i = 0;
	if (subarray == NULL) 
        return ;
	while(subarray[i]!= 0)
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
	while(ptr && *ptr)
	{
		if(ft_strncmp("PATH=",*ptr, 5) == 0)
		{
			ptr_tem = ft_substr(*ptr,5,(ft_strlen(*ptr)-5));
			path = ft_split(ptr_tem, ':');
			free(ptr_tem);
			return(path);
		}
		ptr++;
	}
	return(NULL);
}

//this function return an executable path with command
char	*ft_get_fullpath(char *cmd, char **path)
{
	int		i;
	char	**cmd_tem;
	char	*path_tem;
	char	*exec;

	i = 0;
	cmd_tem = ft_split(cmd, ' ');
	while(path && path[i])
	{
		path_tem = ft_strjoin(path[i], "/");
		exec = ft_strjoin(path_tem, cmd_tem[0]);
		free(path_tem);
		if(access(exec, F_OK | X_OK) == 0)
		{
			ft_free_subarray(cmd_tem);
			return(exec);
		}
		free(exec);
		i++;
	}
	ft_free_subarray(cmd_tem);
	perror("Command not found");
	return(NULL);
}