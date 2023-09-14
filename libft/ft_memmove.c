/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:08:44 by regea-go          #+#    #+#             */
/*   Updated: 2023/04/26 03:19:15 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src0;
	unsigned char	*dst0;
	int				cntr;

	cntr = 0;
	dst0 = (unsigned char *)dst;
	src0 = (unsigned char *)src;
	if ((!dst && !src))
		return (0);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	if (len == 0 || dst == src)
		return (dst);
	while (len--)
		dst0[len] = src0[len];
	return (dst);
}
