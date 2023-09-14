/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:06:12 by regea-go          #+#    #+#             */
/*   Updated: 2023/04/26 03:18:16 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	space;
	void	*ptr;
	void	*src;

	space = count * size;
	ptr = malloc(space);
	if (!ptr)
		return (0);
	src = ptr;
	while (space > 0)
	{
		*(char *)ptr = 0;
		ptr++;
		space--;
	}
	return (src);
}
