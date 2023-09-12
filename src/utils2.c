/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:43:19 by kchan             #+#    #+#             */
/*   Updated: 2023/09/12 11:49:01 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../libft/libft.h"

int ft_close_fd_in_out(int fd_in, int fd_out)
{
	int close_fd_in;
	int close_fd_out;
	
	close_fd_in = close(fd_in); 
	if (close_fd_in < 0)
		perror("close input file error");
	close_fd_out = close(fd_out);
	if (close_fd_out < 0)
		perror("close output file error");
	return(0);
}

int	ft_redirection(int fd_in, int fd_out)
{
	int redirect_stdin;
	int redirect_stdout;

	redirect_stdin = dup2(fd_in, STDIN_FILENO); //stdin file no is now 3 
	if (redirect_stdin < 0)
		perror("redirect stdin error");
	redirect_stdout = dup2(fd_out, STDOUT_FILENO);//stdin file no is now 4	
	if (redirect_stdout < 0)
		perror("redirect stdout error");
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
	ft_close_fd_in_out(fd_in, fd_out);
	cmd_path = ft_get_fullpath(cmd, paths); //join to an executable path;
	exec_return = execve(cmd_path, cmd_parms, NULL);
	if (exec_return < 0)
		perror("could not find program to execute error");
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
	if(pid < 0)
		perror("fork error");
	if (pid == 0)
	{
		child_status = child_process(cmd, paths, fd_in, fd_out);
		if(child_status != 0)
			perror("child process error");
	}
	else
		ft_close_fd_in_out(fd_in, fd_out);
		if (wait(&status) < 0)
			perror("parent process failure");
	return (0);
}
