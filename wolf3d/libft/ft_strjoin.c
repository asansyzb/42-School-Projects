/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:41:05 by asansyzb          #+#    #+#             */
/*   Updated: 2018/10/23 15:41:42 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*dest;

	if (!s1 || !s2)
		return ((void*)0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(dest = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
		return ((void*)0);
	i = -1;
	j = -1;
	while (++i < len1 || ++j <= len2)
	{
		if (i < len1)
			dest[i] = s1[i];
		if (j <= len2)
			dest[len1 + j] = s2[j];
	}
	return (dest);
}
