/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:12:12 by regea-go          #+#    #+#             */
/*   Updated: 2023/05/24 22:36:29 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		cntr;

	cntr = 0;
	if (start >= ft_strlen(s))
	{
		substr = malloc(1);
		if (!substr)
			return (0);
		*substr = '\0';
		return (substr);
	}
	if (!s)
		return (0);
	if (ft_strlen(s) <= len)
		substr = malloc(ft_strlen(s) * sizeof(char) + 1);
	else
		substr = malloc(len * sizeof(char) + 1);
	if (!substr)
		return (0);
	while (cntr < len && s[start] != '\0')
		substr[cntr++] = s[start++];
	substr[cntr] = '\0';
	return (substr);
}
