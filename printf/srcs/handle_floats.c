/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_floats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 23:58:17 by asansyzb          #+#    #+#             */
/*   Updated: 2018/12/07 23:58:18 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	prepare_float(int *sign, long double *n, t_flags *f)
{
	long double	pi;
	int			i;

	i = 0;
	pi = 0.5;
	*sign = 0;
	if (*n < 0)
	{
		*n = -(*n);
		*sign = 1;
	}
	f->precision = (f->precision > -1) ? f->precision : 6;
	while (f->precision >= 0 && i++ < f->precision)
		pi /= 10;
	*n += pi;
}

static char	*ft_ftoa(long double n, t_flags *f)
{
	int		len;
	char	*dst;
	char	*dec;
	int		sign;
	int		pos;

	prepare_float(&sign, &n, f);
	dec = ft_llitoa_base((long long int)n, DECIMAL);
	len = ft_strlen(dec);
	dst = ft_strnew(sign + len + 1 + ((f->precision > 0) ? f->precision : 0));
	pos = sign;
	ft_strcpy(dst + pos, dec);
	pos += len;
	if (f->precision > 0)
		dst[pos++] = '.';
	while (pos < len + sign + ((f->precision > 0) ? (f->precision + 1) : 0))
	{
		dst[pos++] = ((unsigned long long int)(n * 10) % 10) + '0';
		n *= 10;
	}
	if (sign)
		dst[0] = '-';
	ft_strdel(&dec);
	return (dst);
}

char		*convert_float_nbr(void *p, t_flags *f)
{
	char	*str;

	str = NULL;
	str = ft_ftoa(*(long double*)p, f);
	return (str);
}

size_t		print_arg_float(va_list *args, t_flags *f)
{
	long double	n;

	if (f->type == TYPE_L)
		n = (double)va_arg(*args, double);
	else if (f->type == TYPE_LL)
		n = (long double)va_arg(*args, long double);
	else
		n = (double)va_arg(*args, double);
	return (fmt_putnbr(convert_float_nbr((void*)&n, f), f));
}
