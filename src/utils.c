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
#include "../lib/libft/ft_printf.h"
#include "../lib/libft/libft.h"

void	ft_error(char *msg)
{
	perror(msg);
	exit(-1);
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

#include <stdio.h>
//this function return an executable path with command, it should split into two return, command needs file name and command doen't need file name
char	*ft_get_fullpath(char *cmd, char **path)
{
	int		i;
	char	*path_tem;
	char	*exec;
	char	**split_cmd;

	i = 0;
	while(path && path[i])
	{
		split_cmd = ft_split(cmd, ' ');
		path_tem = ft_strjoin(path[i], "/");
		exec = ft_strjoin(path_tem, split_cmd[0]);
		free(split_cmd);
		free(path_tem);
		if(access(exec, F_OK | X_OK) == 0)
			return(exec);
		free(exec);
		i++;
	}
	perror("Command not found");
	return(NULL);
}


int	ft_execute(char *cmd, char **paths, int fd_in, int fd_out) //send cmd1 and splited environ path here
{
	char	**cmd_parms;
	char	*cmd_path;
	int		exec_return;
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		cmd_parms = ft_split(cmd, ' ') ;//write a function to join file name with space
		
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		cmd_path = ft_get_fullpath(cmd, paths); //join to an executable path;
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
