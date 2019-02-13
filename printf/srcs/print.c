/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 01:15:44 by asansyzb          #+#    #+#             */
/*   Updated: 2018/12/05 01:15:47 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	print_arg_char(va_list *args, t_flags *f)
{
	wint_t	n;

	if (f->format == 'C' || (f->format == 'c' && f->type == TYPE_L))
		n = (wint_t)va_arg(*args, wint_t);
	else if (f->format == 'c')
		n = (char)va_arg(*args, int);
	else
		n = (char)'%';
	return (fmt_putchar((char)n, f));
}

static size_t	print_arg_ptr(va_list *args, t_flags *f)
{
	void	*p;
	char	*str;

	str = NULL;
	p = NULL;
	if (f->format == 's' && f->type == TYPE_L)
		f->format = 'S';
	p = (f->format == 'S') ? (wchar_t *)va_arg(*args, wchar_t *)
							: (void *)va_arg(*args, void *);
	if (f->format == 'S' && p)
		str = ft_strwdup((wchar_t*)p);
	else
	{
		if (f->format == 's' && p)
			str = ft_strdup((char*)p);
		else if (f->format == 'p')
		{
			f->prefix = "0x";
			return (fmt_putnbr(convert_nbr(p, f), f));
		}
	}
	if (!str)
		str = (f->format == 'p') ? ft_strdup("0") : ft_strdup("(null)");
	return (fmt_putptr(str, f));
}

static size_t	print_to_ptr(va_list *args, t_flags *f)
{
	int	*p;

	p = (int*)va_arg(*args, int*);
	*p = f->bytes;
	return (0);
}

size_t			print_arg(char **s, t_flags *f, va_list *args)
{
	f->format = **s;
	(*s)++;
	if (ft_strchr("di", f->format))
		return (print_arg_int(args, f));
	else if (ft_strchr("oOuUxX", f->format))
		return (print_arg_uint(args, f));
	else if (ft_strchr("cC%", f->format)
		|| (f->format == 'c' && f->type == TYPE_L))
		return (print_arg_char(args, f));
	else if (ft_strchr("UD", f->format))
		return (print_arg_lint(args, f));
	else if (ft_strchr("fF", f->format))
		return (print_arg_float(args, f));
	else if (ft_strchr("psS", f->format))
		return (print_arg_ptr(args, f));
	else if (f->format == 'n')
		return (print_to_ptr(args, f));
	else if (f->format)
		return (fmt_putchar(f->format, f));
	return (0);
}
