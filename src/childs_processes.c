/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:52:06 by regea-go          #+#    #+#             */
/*   Updated: 2023/09/02 10:00:40 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	child_process_first(int pipefd[], int fd, char *argv[], char *envp[])
{
	char	**args;

	if (dup2(fd, STDIN_FILENO) < 0)
		return (ft_print_error(REDIRECT_ERR));
	close(fd);
	if (dup2(pipefd[1], STDOUT_FILENO) < 0)
		return (ft_print_error(REDIRECT_ERR));
	close(pipefd[0]);
	close(pipefd[1]);
	args = ft_split(argv[2], ' ');
	if (execve(abs_bin_path(args[0], get_paths(envp)), args, envp) != 0)
		return (ft_print_error(EXEC_ERR));
	return (0);
}

int	child_process_last(int pipefd[], int fd, char *argv[], char *envp[])
{
	char	**args;

	if (dup2(pipefd[0], STDIN_FILENO) < 0)
		return (ft_print_error(REDIRECT_ERR));
	close(pipefd[0]);
	fd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0755);
	if (fd < 0)
		return (ft_print_error(FILE_ERR));
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (ft_print_error(REDIRECT_ERR));
	close(fd);
	args = ft_split(argv[3], ' ');
	if (execve(abs_bin_path(args[0], get_paths(envp)), args, envp) != 0)
		return (ft_print_error(EXEC_ERR));
	return (0);
}
