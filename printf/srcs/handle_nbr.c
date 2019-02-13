/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 00:23:59 by asansyzb          #+#    #+#             */
/*   Updated: 2018/12/08 00:24:01 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	print_arg_lint(va_list *args, t_flags *f)
{
	long int	n;

	f->base = DECIMAL;
	n = (long int)va_arg(*args, long int);
	return (fmt_putnbr(convert_nbr((void*)&n, f), f));
}

size_t	print_arg_uint(va_list *args, t_flags *f)
{
	unsigned long long int	n;

	f->base = DECIMAL;
	if (f->format == 'o' || f->format == 'O')
		f->base = OCTAL;
	else if (f->format == 'x' || f->format == 'X')
		f->base = (f->format == 'x') ? HEX : HEX_UP;
	if (f->type == TYPE_LL || f->format == 'U')
		n = (unsigned long long int)va_arg(*args, unsigned long long int);
	else if (f->type == TYPE_L || f->format == 'O')
		n = (unsigned long int)va_arg(*args, unsigned long int);
	else if (f->type == TYPE_H)
		n = (unsigned short)va_arg(*args, unsigned int);
	else if (f->type == TYPE_HH)
		n = (unsigned char)va_arg(*args, unsigned int);
	else if (f->type == TYPE_J)
		n = (uintmax_t)va_arg(*args, uintmax_t);
	else if (f->type == TYPE_Z)
		n = (ssize_t)va_arg(*args, ssize_t);
	else
		n = (unsigned int)va_arg(*args, unsigned int);
	return (fmt_putnbr(convert_nbr((void*)&n, f), f));
}

size_t	print_arg_int(va_list *args, t_flags *f)
{
	long long int	n;

	if (f->type == TYPE_LL)
		n = (long long)va_arg(*args, long long int);
	else if (f->type == TYPE_L)
		n = (long)va_arg(*args, long int);
	else if (f->type == TYPE_H)
		n = (short)va_arg(*args, int);
	else if (f->type == TYPE_HH)
		n = (signed char)va_arg(*args, int);
	else if (f->type == TYPE_J)
		n = (intmax_t)va_arg(*args, intmax_t);
	else if (f->type == TYPE_Z)
		n = (size_t)va_arg(*args, size_t);
	else
		n = (int)va_arg(*args, int);
	return (fmt_putnbr(convert_nbr((void*)&n, f), f));
}
