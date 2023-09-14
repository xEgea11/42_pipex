/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:12:06 by regea-go          #+#    #+#             */
/*   Updated: 2023/08/30 15:55:56 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*
 * @brief Get an array of env paths; we assume PATH var is 
 *		  going to be present every time
 * 		  and its going to be called PATH
 * @param envp from main 
 * @return char ** (paths) 
 */
char	**get_paths(char *envp[])
{
	int		i;
	int		flag;
	char	**path_env_var;
	char	**paths;

	i = 0;
	flag = 0;
	while (envp[i] && flag == 0)
	{
		if (ft_strnstr(envp[i], "PATH", 4))
			flag = 1;
		if (flag == 0)
			i++;
	}
	path_env_var = ft_split(envp[i], '=');
	paths = ft_split(path_env_var[1], ':');
	return (paths);
}

/**
 * @brief finds the path of a command
 * 
 * @param command
 * @param paths
 * @return absolute path 
 */
char	*abs_bin_path(char *cmd, char **envp)
{
	int		i;
	char	*slash_cmd;
	char	*possible_bin;

	i = 0;
	slash_cmd = ft_strjoin("/", cmd);
	while (envp[i])
	{
		possible_bin = ft_strjoin(envp[i], slash_cmd);
		if (access(possible_bin, F_OK) == 0)
		{
			if (access(possible_bin, X_OK) < 0)
			{
				perror("Permission denied\n");
				return (NULL);
			}
			else
				return (possible_bin);
		}
		i++;
	}
	return (possible_bin);
}

int	ft_print_error(char *error)
{
	perror(error);
	return (1);
}
