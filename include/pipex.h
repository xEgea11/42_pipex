/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:39:29 by regea-go          #+#    #+#             */
/*   Updated: 2023/08/30 16:04:14 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include <sys/types.h>
# include <errno.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>

# define ARG_ERR "Incorrect arguments"
# define FILE_ERR "Can't operate the file"
# define PIPE_ERR "Can't open the pipe"
# define FORK_ERR "Can't fork the process"
# define EXEC_ERR "Can't execute the command"
# define REDIRECT_ERR "Can't redirect"

char	**get_paths(char *envp[]);
char	*abs_bin_path(char *cmd, char **envp);
int		ft_print_error(char *error);
int		first_exec(int fd, int pipefd[], char *argv[], char *envp[]);
int		last_exec(int pipefd[], char *argv[], char *envp[]);
int		pipex(int argc, char *argv[], char *envp[]);

int		child_process_first(int pipefd[], int fd, char *argv[], char *envp[]);
int		child_process_last(int pipefd[], int fd, char *argv[], char *envp[]);

#endif