/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:05:21 by kchan             #+#    #+#             */
/*   Updated: 2023/09/26 13:07:39 by kchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>

int			check_cmd(char **cmd_parms);
void		ft_error(char *msg);
void		ft_free_subarray(char **subarray);
char		**ft_get_path(char **env);
char		*ft_get_fullpath(char *cmd, char **path);
int			ft_close_fd_in_out(int fd_in, int fd_out);
int			ft_redirection(int fd_in, int fd_out);
int			child_process(char *cmd, char **paths, int fd_in, int fd_out);
int			ft_execute(char *cmd, char **paths, int fd_in, int fd_out);
void		ft_file_initialization(int file_fd[], char *infile, char *outfile);
void		exit_handler(int n_exit);

#endif