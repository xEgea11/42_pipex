/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:38:42 by regea-go          #+#    #+#             */
/*   Updated: 2023/09/02 10:18:21 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * @brief Last call of redirections; opens a file and saves information to it
 * 
 * @param pipefd Gets the pipe where it will read from 
 * @param argv Arguments (Last command and file to write on)
 * @param envp list of paths
 * @return int returns 1 if error; 0 if success 
 */
int	last_exec(int pipefd[], char *argv[], char *envp[])
{
	pid_t		id;
	int			fd;

	close(pipefd[1]);
	fd = 0;
	id = fork();
	if (id == 0)
	{	
		if (child_process_last(pipefd, fd, argv, envp) == 1)
			return (1);
	}
	else
	{
		waitpid(id, NULL, WNOHANG);
		close(pipefd[0]);
	}
	return (0);
}

/**
 * @brief First command execution 
 * 
 * @param fd File to read from
 * @param pipefd pipe to write on
 * @param argv arguments (filename to read from and command)
 * @param envp paths
 * @return int returns 1 if error; 0 if success
 */
int	first_exec(int fd, int pipefd[], char *argv[], char *envp[])
{
	pid_t		id;	

	id = fork();
	if (id < 0)
		return (ft_print_error(FORK_ERR));
	if (id == 0)
	{
		if (child_process_first(pipefd, fd, argv, envp) == 1)
			return (1);
	}
	else
	{
		waitpid(id, NULL, WNOHANG);
		if (last_exec(pipefd, argv, envp) != 0)
			return (1);
	}
	return (0);
}

/**
 * @brief main function of the project, 
 * it holds the calls of the others functions
 * 
 * @param argc arg count
 * @param argv parameters
 * @param envp path names
 * @return int returns 1 if not a good execution, 
 * returns 0 if everything is correct
 */
int	pipex(int argc, char *argv[], char *envp[])
{
	int		pipefd[2];
	int		status;
	int		fd;

	if (argc != 5)
		return (ft_print_error(ARG_ERR));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_print_error(FILE_ERR));
	if (pipe(pipefd) < 0)
		return (ft_print_error(PIPE_ERR));
	status = first_exec (fd, pipefd, argv, envp);
	return (status);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	status;

	status = pipex(argc, argv, envp);
	return (status);
}
