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

// void	exit_handler(int n_exit); //not sure to addd or not
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
#endif