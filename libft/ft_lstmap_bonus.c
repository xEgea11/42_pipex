/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 03:45:18 by regea-go          #+#    #+#             */
/*   Updated: 2023/05/24 21:32:13 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*dst;

	node = ft_lstnew(0);
	if (!lst || !del)
		return (0);
	dst = node;
	while (lst->next != 0)
	{
		node->content = f(lst->content);
		node->next = ft_lstnew(0);
		if (!node->content || !node->next)
		{
			ft_lstclear(&dst, del);
			return (dst);
		}
		node = node->next;
		lst = lst->next;
	}
	node->content = f(lst->content);
	node->next = 0;
	return (dst);
}
