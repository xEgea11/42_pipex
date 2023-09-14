/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:15:14 by regea-go          #+#    #+#             */
/*   Updated: 2023/04/26 03:20:01 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;
	size_t	counter2;
	size_t	dst_len;
	size_t	src_len;

	counter = 0;
	counter2 = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	if (src == 0)
		return (dst_len);
	if (dstsize == 0)
		return (src_len);
	while (*(dst + counter) != '\0')
		counter++;
	while (*(src + counter2) != '\0' && (counter + counter2) < dstsize - 1)
	{
		*(dst + counter + counter2) = *(src + counter2);
		counter2++;
	}
	if ((counter + counter2) < dstsize)
		*(dst + counter + counter2) = '\0';
	return (dst_len + src_len);
}
