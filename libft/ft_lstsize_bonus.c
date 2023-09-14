/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 03:45:38 by regea-go          #+#    #+#             */
/*   Updated: 2023/04/26 09:17:19 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*itr;

	size = 0;
	itr = lst;
	if (lst == 0)
		return (0);
	while (itr != 0)
	{
		itr = itr->next;
		size++;
	}
	return (size);
}
