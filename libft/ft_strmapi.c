/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 01:59:24 by regea-go          #+#    #+#             */
/*   Updated: 2023/04/26 03:20:19 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	char	*dest;

	dest = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!dest)
		return (0);
	index = 0;
	while (s[index] != '\0')
	{
		dest[index] = (char)f(index, s[index]);
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
