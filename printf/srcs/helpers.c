/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 01:15:01 by asansyzb          #+#    #+#             */
/*   Updated: 2018/12/07 23:46:33 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr_tobuf(char *src, t_flags *f)
{
	int	k;

	k = 0;
	while (src[k])
	{
		if (f->i + k >= BUFF_SIZE)
		{
			write(1, f->buff, f->i);
			ft_bzero((void*)f->buff, BUFF_SIZE);
			f->i = 0;
		}
		f->buff[f->i] = src[k];
		f->i++;
		k++;
	}
}

void	ft_putnchar_tobuf(char c, t_flags *f, int len)
{
	int	k;

	k = 0;
	while (k < len && k < BUFF_SIZE)
	{
		if (f->i + k >= BUFF_SIZE)
		{
			write(1, f->buff, f->i);
			ft_bzero((void*)f->buff, BUFF_SIZE);
			f->i = 0;
		}
		f->buff[f->i] = c;
		f->i++;
		k++;
	}
}

char	*convert_nbr(void *p, t_flags *f)
{
	char	*str;

	str = NULL;
	if (ft_strchr("oOuUxX", f->format))
		str = ft_ullitoa_base(*(unsigned long long int*)p, f->base);
	else if (f->format == 'p')
		str = ft_ullitoa_base((unsigned long)p, HEX);
	else
		str = ft_llitoa_base(*(long long int*)p, DECIMAL);
	return (str);
}

size_t	ft_strwlen(wchar_t *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strwdup(wchar_t *s)
{
	size_t	i;
	char	*dest;

	if (!(dest = (char*)malloc(sizeof(char) * (ft_strwlen(s) + 1))))
		return ((void *)0);
	i = 0;
	while (s[i])
	{
		dest[i] = (char)s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
