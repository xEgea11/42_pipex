/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:09:33 by regea-go          #+#    #+#             */
/*   Updated: 2023/05/24 14:51:28 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*str;
	size_t		size;
	size_t		cntr;

	size = 0;
	cntr = 0;
	while (s1[size] != '\0')
		size++;
	str = malloc(size * sizeof(char) + 1);
	if (!str)
		return (0);
	while (s1[cntr] != '\0')
	{
		str[cntr] = (char)s1[cntr];
		cntr++;
	}
	str[cntr] = '\0';
	return ((char *)str);
}
