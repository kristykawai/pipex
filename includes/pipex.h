#ifndef PIPEX_H
 #define PIPEX_H
 
 /* to write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* malloc, free, exit */
# include <stdlib.h>
/* open, unlink */
# include <fcntl.h>
/* waitpid, wait */
# include <sys/wait.h>
/* strerror */
# include <string.h>
/*to perror*/
# include <stdio.h>

// /*utils.c*/
// int		open_file(char *file, int n);
// // char	*my_getenv(char *name, char **env);
// // char	*get_path(char *cmd, char **env);
// void	exec(char *cmd, char **env);
// // void	ft_free_tab(char **tab);
// void	exit_handler(int n_exit);

//own function
void	ft_error(char *msg);
void    ft_free_subarray(char **subarray);
// char 	**cmd_filename(char *cmd, char *infile);
// int 	check_execve_parameter(char *cmd_path, char **cmd_parms, char *infile);
char	**ft_get_path(char **env);
char	*ft_get_fullpath(char *cmd, char **path);
int	    ft_execute(char *cmd, char **paths, int fd_in, int fd_out);
void	ft_error(char *str);
void    ft_file_initialization(int file_fd[], char *infile, char *outfile);
#endif