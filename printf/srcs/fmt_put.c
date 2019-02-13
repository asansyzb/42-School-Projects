/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:05:38 by asansyzb          #+#    #+#             */
/*   Updated: 2018/12/05 00:54:33 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	fmt_putchar(char c, t_flags *f)
{
	size_t	len;

	len = 1;
	handle_flags(f, &c);
	if (!f->minus)
		ft_putnchar_tobuf(f->padding_char, f, f->width - 1);
	ft_putnchar_tobuf(c, f, 1);
	if (f->minus)
		ft_putnchar_tobuf(f->padding_char, f, f->width - 1);
	write(1, f->buff, f->i);
	return (ft_max(f->width, 1));
}

size_t	fmt_putptr(char *p, t_flags *f)
{
	size_t	len;
	size_t	p_len;
	int		padding;

	handle_flags(f, p);
	len = ft_strlen(p);
	p_len = (f->prefix) ? ft_strlen(f->prefix) : 0;
	padding = f->width - (int)len - p_len;
	if (f->padding_char == '0' && f->prefix)
		ft_putstr_tobuf(f->prefix, f);
	if (!f->minus && f->padding_char)
		ft_putnchar_tobuf(f->padding_char, f, padding);
	if (f->padding_char == ' ' && f->prefix)
		ft_putstr_tobuf(f->prefix, f);
	if (f->precision > 0 && f->precision < (int)len)
		ft_putnchar_tobuf(f->padding_char, f, f->precision - (int)len);
	ft_putstr_tobuf(p, f);
	if (f->minus && f->padding_char)
		ft_putnchar_tobuf(f->padding_char, f, padding);
	write(1, f->buff, f->i);
	ft_strdel(&p);
	return (ft_max(f->width, (int)len + (int)p_len));
}

size_t	fmt_putnbr(char *p, t_flags *f)
{
	size_t	len;
	size_t	p_len;
	int		padding;

	if (*p == '-' && p++)
		f->prefix = "-";
	handle_flags(f, p);
	len = ft_strlen(p);
	p_len = (f->prefix) ? ft_strlen(f->prefix) : 0;
	padding = f->width - ft_max((int)len, f->precision) - p_len;
	if (f->padding_char == '0' && f->prefix)
		ft_putstr_tobuf(f->prefix, f);
	if (!f->minus && f->padding_char)
		ft_putnchar_tobuf(f->padding_char, f, padding);
	if (f->padding_char == ' ' && f->prefix)
		ft_putstr_tobuf(f->prefix, f);
	if (f->precision > (int)len)
		ft_putnchar_tobuf('0', f, f->precision - (int)len);
	ft_putstr_tobuf(p, f);
	if (f->minus && f->padding_char)
		ft_putnchar_tobuf(f->padding_char, f, padding);
	write(1, f->buff, f->i);
	len += (f->precision > (int)len) ? (f->precision - (int)len) : 0;
	free((f->prefix && ft_strchr(f->prefix, '-')) ? (p - 1) : p);
	return (ft_max(f->width, (int)len + (int)p_len));
}
