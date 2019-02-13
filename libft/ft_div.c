/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:32:01 by asansyzb          #+#    #+#             */
/*   Updated: 2018/10/23 20:45:35 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_div	*ft_div(int numer, int denom)
{
	t_div	*dest;

	if (!(dest = malloc(sizeof(t_div))))
		return ((void*)0);
	dest->quot = (numer / denom);
	dest->rem = (numer % denom);
	return (dest);
}
