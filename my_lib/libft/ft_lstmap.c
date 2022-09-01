/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:25:22 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/01 21:20:49 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*second_list;
	t_list	*second_list_back;

	if (!lst)
		return (NULL);
	second_list = NULL;
	while (lst != NULL)
	{
		second_list_back = ft_lstnew((*f)(lst->content));
		ft_lstadd_back(&second_list, second_list_back);
		if (!second_list_back)
		{
			ft_lstclear(&second_list, del);
			return (0);
		}
		lst = lst->next;
	}
	return (second_list);
}
