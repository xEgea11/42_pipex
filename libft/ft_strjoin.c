/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:09:39 by regea-go          #+#    #+#             */
/*   Updated: 2023/04/26 03:19:57 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		cntr;
	int		cntr2;

	cntr = 0;
	cntr2 = 0;
	if (s1 && !s2)
		return ((char *)s1);
	if (!s1)
		return (0);
	s3 = (char *)malloc ((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!s3)
		return (0);
	while (s1[cntr] != '\0')
	{
		s3[cntr] = (char)s1[cntr];
		cntr++;
	}
	while (s2[cntr2] != '\0')
		s3[cntr++] = (char)s2[cntr2++];
	s3[cntr] = '\0';
	return (s3);
}
