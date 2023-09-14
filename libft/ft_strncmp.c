/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:11:17 by regea-go          #+#    #+#             */
/*   Updated: 2023/04/26 03:20:25 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			counter;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	ptr = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	counter = 1;
	if (n == 0)
		return (0);
	while (*ptr == *ptr2 && (*ptr != '\0' && *ptr2 != '\0') && counter < n)
	{
		ptr++;
		ptr2++;
		counter++;
	}
	return (*ptr - *ptr2);
}
