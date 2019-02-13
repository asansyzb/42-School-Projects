/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:30:53 by asansyzb          #+#    #+#             */
/*   Updated: 2018/10/23 15:31:22 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*dest;

	if (!(dest = (char*)malloc(sizeof(char) * size + 1)))
		return ((void*)0);
	ft_bzero(dest, size + 1);
	return (dest);
}
