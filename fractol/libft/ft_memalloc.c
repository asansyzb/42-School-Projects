/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:32:38 by asansyzb          #+#    #+#             */
/*   Updated: 2018/10/23 15:33:02 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*dest;

	if (!(dest = (void*)malloc(size)))
		return ((void *)0);
	ft_bzero(dest, size);
	return (dest);
}
