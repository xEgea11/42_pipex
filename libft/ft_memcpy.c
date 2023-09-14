/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:08:38 by regea-go          #+#    #+#             */
/*   Updated: 2023/04/26 03:19:08 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*dst0;

	dst0 = dst;
	if (!dst && !src)
		return (0);
	while (n > 0)
	{
		*(char *)dst0 = *(char *)src;
		dst0++;
		src++;
		n--;
	}
	return (dst);
}
