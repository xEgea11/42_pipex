/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 03:44:37 by regea-go          #+#    #+#             */
/*   Updated: 2023/04/28 01:38:11 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*itr;

	if (!lst)
		return ;
	while (*lst != 0)
	{
		itr = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = itr;
	}
}
