/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:43:19 by kchan             #+#    #+#             */
/*   Updated: 2023/09/18 16:28:10 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../libft/libft.h"

int	ft_close_fd_in_out(int fd_in, int fd_out)
{
	int	close_fd_in;
	int	close_fd_out;

	close_fd_in = close(fd_in);
	if (close_fd_in < 0)
		perror("close input file error");
	close_fd_out = close(fd_out);
	if (close_fd_out < 0)
		perror("close output file error");
	return (0);
}

int	ft_redirection(int fd_in, int fd_out)
{
	int	redirect_stdin;
	int	redirect_stdout;

	redirect_stdin = dup2(fd_in, STDIN_FILENO);
	if (redirect_stdin < 0)
		perror("redirect stdin error");
	redirect_stdout = dup2(fd_out, STDOUT_FILENO);
	if (redirect_stdout < 0)
		perror("redirect stdout error");
	return (0);
}

int	check_cmd(char **cmd_parms)
{
	if (cmd_parms[0][0] == '/' || cmd_parms[0][0] == '.' || cmd_parms[0][0] == '~')
		return (1);
	return (0);
}

int	child_process(char *cmd, char **paths, int fd_in, int fd_out)
{
	char	**cmd_parms;
	char	*cmd_path;
	int		exec_return;

	cmd_parms = ft_split(cmd, ' ');
	if (!cmd_parms)
		perror("command parameter error");
	ft_redirection(fd_in, fd_out);
	ft_close_fd_in_out(fd_in, fd_out);
	if (check_cmd (cmd_parms) == 1)
		cmd_path = ft_strdup(cmd_parms[0]);
	else
		cmd_path = ft_get_fullpath(cmd, paths);
	exec_return = execve(cmd_path, cmd_parms, NULL);
	if (exec_return < 0)
		perror("could not find program to execute error");
	ft_free_subarray(cmd_parms);
	free(cmd_path);
	exit(exec_return);
	return (0);
}

int	ft_execute(char *cmd, char **paths, int fd_in, int fd_out)
{
	int		pid;
	int		status;
	int		child_status;

	status = 0;
	pid = fork();
	if (pid < 0)
		perror("fork error");
	if (pid == 0)
	{
		child_status = child_process(cmd, paths, fd_in, fd_out);
		if (child_status != 0)
			perror("child process error");
	}
	else
		ft_close_fd_in_out(fd_in, fd_out);
	if (wait(&status) < 0)
		perror("parent process failure");
	return (0);
}
