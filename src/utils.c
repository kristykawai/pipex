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
#include "../libft/libft.h"

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

int	ft_redirection(int fd_in, int fd_out)
{
	int redirect_stdin;
	int redirect_stdout;
	int close_fd_in;
	int close_fd_out;

	redirect_stdin = dup2(fd_in, STDIN_FILENO); //stdin file no is now 3 
	if (redirect_stdin < 0)
		perror("redirect stdin error");
	redirect_stdout = dup2(fd_out, STDOUT_FILENO);//stdin file no is now 4	
	if (redirect_stdout < 0)
		perror("redirect stdout error");
	close_fd_in = close(fd_in); 
	if (close_fd_in < 0)
		perror("close input file error");
	close_fd_out = close(fd_out);
	if (close_fd_out < 0)
		perror("close output file error");
	return(0);
}

int child_process(char *cmd, char **paths, int fd_in, int fd_out)
{
	char	**cmd_parms;
	char	*cmd_path;
	int		exec_return;

	cmd_parms = ft_split(cmd, ' ') ;//write a function to join file name with space
	if (!cmd_parms)
		perror("command parameter error");
	ft_redirection(fd_in, fd_out);
	cmd_path = ft_get_fullpath(cmd, paths); //join to an executable path;
	exec_return = execve(cmd_path, cmd_parms, NULL);
	if (exec_return == -1)
		perror("command execution error");
	ft_free_subarray(cmd_parms);
	free(cmd_path);
	exit(exec_return);
	return(0);
}

int	ft_execute(char *cmd, char **paths, int fd_in, int fd_out) //send cmd1 and splited environ path here
{
	int		pid;
	int		status;
	int		child_status;

	status = 0;
	pid = fork();
	if(pid == -1)
		perror("fork error");
	if (pid == 0)
	{
		child_status = child_process(cmd, paths, fd_in, fd_out);
		if(child_status != 0)
			perror("child process error");
	}
	else
    	if (wait(&status)== -1)
			perror("wait()error");
	return (status);
}
