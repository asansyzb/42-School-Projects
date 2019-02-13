/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:21:05 by asansyzb          #+#    #+#             */
/*   Updated: 2018/10/23 15:25:13 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin;

	if (!(new = f(lst)))
		return (NULL);
	begin = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new->next = f(lst)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (begin);
}
