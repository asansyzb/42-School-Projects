/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:08:35 by asansyzb          #+#    #+#             */
/*   Updated: 2018/10/23 20:26:52 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *a, void *b, size_t size)
{
	void	*t;

	if (!(t = malloc(size)))
		return ;
	memcpy(t, a, size);
	memcpy(a, b, size);
	memcpy(b, t, size);
	free(t);
}
