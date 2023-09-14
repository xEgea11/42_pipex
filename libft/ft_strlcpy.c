/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:20:46 by regea-go          #+#    #+#             */
/*   Updated: 2023/04/26 03:20:05 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		counter;
	size_t		len;

	counter = 0;
	len = ft_strlen(src);
	if (src == 0 && len != 0)
	{
		*dst = '\0';
		return (0);
	}
	if (dstsize == 0)
		return (len);
	while (*(src + counter) != '\0' && counter < (dstsize - 1))
	{
		*(dst + counter) = *(src + counter);
		counter ++;
	}
	*(dst + counter) = '\0';
	return (len);
}
