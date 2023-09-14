/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:11:27 by regea-go          #+#    #+#             */
/*   Updated: 2023/04/28 04:14:22 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		cntr;
	size_t		cntr2;
	char		*ptr;

	cntr = 0;
	cntr2 = 0;
	if (*needle == 0)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (haystack[cntr] != '\0')
	{
		while (haystack[cntr + cntr2] == needle[cntr2]
			&& needle[cntr2] != '\0' && (cntr + cntr2) < len)
				cntr2++;
		if (needle[cntr2] == '\0')
		{
			ptr = (char *)&haystack[cntr];
			return (ptr);
		}
		cntr++;
		cntr2 = 0;
	}
	return (0);
}
