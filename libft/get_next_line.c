/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:05:02 by regea-go          #+#    #+#             */
/*   Updated: 2023/05/30 19:06:48 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*copy_line(char *buffer)
{
	char		*line;
	size_t		i;
	size_t		len;

	i = 0;
	if (!buffer)
		return (0);
	len = ft_linelen(buffer);
	line = malloc (len * sizeof(char) + 1);
	if (!line)
		return (0);
	while (buffer[i] != '\n' && i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}	
	line[i] = '\0';
	return (line);
}

char	*update_buffer(char	*buffer)
{
	char		*tmp;
	size_t		cntr;
	size_t		cntr2;

	cntr = 0;
	cntr2 = 0;
	if (!ft_strchr(buffer, '\n'))
		return (ft_free(&buffer));
	while (buffer[cntr] != '\n')
		cntr++;
	tmp = malloc(ft_strlen(&buffer[++cntr]) * sizeof(char) + 1);
	if (!tmp)
		return (ft_free(&buffer));
	while (buffer[cntr + cntr2] != '\0')
	{
		tmp[cntr2] = buffer[cntr + cntr2];
		cntr2++;
	}
	tmp[cntr2] = '\0';
	ft_free(&buffer);
	return (tmp);
}

char	*read_line(char *buffer, int fd)
{
	char	*aux;
	int		bytes_read;

	bytes_read = 1;
	aux = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!aux)
		return (ft_free(&buffer));
	aux[0] = '\0';
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, aux, BUFFER_SIZE);
		if ((bytes_read == 0 && buffer[0] == '\0'))
			return (ft_free(&buffer), ft_free(&aux));
		if (bytes_read > 0)
		{
			aux[bytes_read] = '\0';
			buffer = ft_strjoin_gnl(buffer, aux);
		}
	}
	free(aux);
	if (bytes_read == -1)
		return (ft_free(&buffer));
	return (buffer);
}

char	*get_next_line(int fd)
{	
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!buffer)
	{
		buffer = malloc(sizeof(char) * 1);
		if (!buffer)
			return (0);
		buffer[0] = '\0';
	}
	buffer = read_line(buffer, fd);
	if (!buffer)
		return (0);
	line = copy_line(buffer);
	if (!line)
		return (ft_free(&buffer));
	buffer = update_buffer(buffer);
	if (!buffer)
		return (line);
	return (line);
}
