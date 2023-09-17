/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:17:04 by kchan             #+#    #+#             */
/*   Updated: 2023/09/12 14:43:36 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../libft/libft.h"

// tbc tmp file
	// char	*temp_file;
	// int		temp_file_fd;
	// int		urandom_fd;
	// int		bytes_rd;
	// char	buffer[1024];
	// temp_file = "tempfileXXXXXX";
	// temp_file_fd = open(temp_file, O_RDWR | O_CREAT | O_EXCL, 0600);
	// if (temp_file_fd == -1)
	// {
	// 	perror("Failed to create temporary file");
	// 	exit(EXIT_FAILURE);
	// }
	// urandom_fd = open("/dev/urandom", O_RDONLY);
	// if (urandom_fd < 0)
	// {
	// 	perror("Error opening /dev/urandom");
	// 	close(temp_file_fd);
	// 	exit(EXIT_FAILURE);
	// }
	// bytes_rd = read(urandom_fd, buffer, sizeof(buffer));
	// if (bytes_rd < 0)
	// {
	// 	perror("Error reading from /dev/urandom");
	// 	close(urandom_fd);
	// 	exit(EXIT_FAILURE);
	// }

void	ft_file_initialization(int file_fd[], char *infile, char *outfile)
{
	file_fd[0] = open(infile, O_RDONLY, 0644);
	if (file_fd[0] < 0)
	{
		perror("Error opening infile");
		exit(EXIT_FAILURE);
	}
	file_fd[1] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_fd[1] < 0)
	{
		perror("Error creating outfile");
		close(file_fd[0]);
		exit(EXIT_FAILURE);
	}
}

static void	ft_pipex(int argc, char *argv[], char **paths)
{
	int		file_fd[2];
	int		pipe_fd[2];
	int		last_pipe_fd_0;
	int		i;

	last_pipe_fd_0 = -1;
	ft_file_initialization(file_fd, argv[1], argv[argc - 1]);
	i = 2;
	while (i < argc -1)
	{
		if (pipe(pipe_fd) < 0)
		{
			perror("Error creating pipe fd");
			exit(EXIT_FAILURE);
		}
		if (i == 2)
			ft_execute(argv[i], paths, file_fd[0], pipe_fd[1]);
		else if (i == argc - 2)
			ft_execute(argv[i], paths, last_pipe_fd_0, file_fd[1]);
		else
			ft_execute(argv[i], paths, last_pipe_fd_0, pipe_fd[1]);
		last_pipe_fd_0 = dup(pipe_fd[0]);
		i++;
	}
	close(last_pipe_fd_0);
}

int	main(int argc, char *argv[], char *env[])
{
	char	**paths;

	if (argc < 5)
	{
		ft_putstr_fd("Error: Too less arguments.", 2);
		exit(EXIT_FAILURE);
	}
	else
	{
		paths = ft_get_path(env);
		ft_pipex(argc, argv, paths);
		ft_free_subarray(paths);
	}
	exit(0);
	return (0);
}
