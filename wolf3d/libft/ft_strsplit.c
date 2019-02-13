/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:41:54 by asansyzb          #+#    #+#             */
/*   Updated: 2018/10/23 16:32:51 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			words_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static int	word_len_count(char const *s, char c)
{
	int len;

	len = 0;
	while (*s == c)
		s++;
	while (*s && *s++ != c)
		len++;
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**dest;

	if (!s || !(dest = (char**)malloc(sizeof(char*) * (words_count(s, c) + 1))))
		return ((void*)0);
	i = 0;
	j = 0;
	while (i < words_count(s, c))
	{
		k = 0;
		if (!(dest[i] = ft_strnew(word_len_count(&s[j], c) + 1)))
			dest[i] = (void*)0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			dest[i][k++] = s[j++];
		dest[i][k] = '\0';
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int			*ft_strsplit_toi(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		*dest;
	char	*tmp;

	if (!s || !(dest = (int*)malloc(sizeof(int) * words_count(s, c))))
		return ((void*)0);
	i = -1;
	j = 0;
	while (++i < words_count(s, c))
	{
		k = 0;
		if (!(tmp = ft_strnew(word_len_count(&s[j], c) + 1)))
			dest[i] = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			tmp[k++] = s[j++];
		tmp[k] = '\0';
		dest[i] = ft_atoi(tmp);
		ft_strdel(&tmp);
	}
	return (dest);
}
