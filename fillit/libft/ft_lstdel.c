/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:55:30 by asansyzb          #+#    #+#             */
/*   Updated: 2018/10/23 18:15:38 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*lst;

	lst = *alst;
	if (alst)
	{
		while (lst)
		{
			next = lst->next;
			del(lst->content, lst->content_size);
			free(lst);
			lst = next;
		}
		*alst = (void*)0;
	}
}
