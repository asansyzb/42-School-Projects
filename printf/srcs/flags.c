/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 01:08:40 by asansyzb          #+#    #+#             */
/*   Updated: 2018/12/05 01:08:42 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		init_flags(t_flags *f)
{
	f->space = 0;
	f->plus = 0;
	f->minus = 0;
	f->zero = 0;
	f->hash = 0;
	f->type = 0;
	f->precision = -1;
	f->width = 0;
	f->i = 0;
	f->buff[BUFF_SIZE] = '\0';
	f->prefix = NULL;
	ft_bzero(f->buff, BUFF_SIZE);
}

static void	handle_hex_flag(t_flags *f, char *p)
{
	if (f->hash && *p != '0' && *p != 0)
	{
		if (f->format == 'x')
			f->prefix = "0x";
		else if (f->format == 'X')
			f->prefix = "0X";
		else if ((f->format == 'o' || f->format == 'O') &&
				(f->precision < (int)ft_strlen(p) || f->precision < 0))
			f->prefix = "0";
	}
}

static void	handle_zerominus_flag(t_flags *f)
{
	if (f->minus || !f->zero || ((f->format == 'd' || f->format == 'i')
		&& f->precision >= 0))
		f->padding_char = ' ';
	else
		f->padding_char = '0';
}

void		handle_flags(t_flags *f, char *p)
{
	handle_hex_flag(f, p);
	handle_zerominus_flag(f);
	if (f->space && ((f->prefix && !ft_strchr(f->prefix, '-')) || !f->prefix)
			&& (f->format == 'd' || f->format == 'i' || f->format == 'f'))
		f->prefix = " ";
	if (f->plus && ((f->prefix && !ft_strchr(f->prefix, '-')) || !f->prefix)
			&& (f->format == 'd' || f->format == 'i' || f->format == 'f'))
		f->prefix = "+";
	if (((f->precision == 0 && *p == '0') &&
			(f->base != OCTAL || (f->base == OCTAL && !f->hash)))
			|| (f->precision == 0 && f->format == 's'))
		*p = '\0';
	if (f->precision > 0 && f->precision < (int)ft_strlen(p)
		&& f->format == 's')
		p[f->precision] = '\0';
}
