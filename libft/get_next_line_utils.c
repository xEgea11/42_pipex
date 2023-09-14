/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:05:05 by regea-go          #+#    #+#             */
/*   Updated: 2023/05/30 18:59:03 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count += 1;
	return (count);
}

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_strjoin_gnl(char *buffer, char *aux)
{
	char		*new_buf;
	size_t		cntr;
	size_t		cntr2;

	cntr = 0;
	cntr2 = 0;
	if (!buffer || !aux)
		return (0);
	new_buf = malloc(((ft_strlen(buffer) + ft_strlen(aux)) * sizeof(char)) + 1);
	if (!new_buf)
		return (ft_free(&buffer));
	while (buffer[cntr] != '\0')
	{
		new_buf[cntr] = buffer[cntr];
		cntr++;
	}
	while (aux[cntr2] != '\0')
		new_buf[cntr++] = aux[cntr2++];
	new_buf[cntr] = '\0';
	ft_free(&buffer);
	return (new_buf);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr != '\0' && *ptr != (char)c)
		ptr++;
	if (*ptr == (char)c)
		return (ptr);
	return (0);
}

size_t	ft_linelen(char *str)
{
	size_t	size;

	size = 0;
	while (str[size] != '\n' && str[size] != '\0')
		size++;
	if (str[size] == '\n')
		size++;
	return (size);
}
