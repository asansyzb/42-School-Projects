/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 01:06:44 by asansyzb          #+#    #+#             */
/*   Updated: 2018/12/05 01:06:48 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	handle_format(char **s, t_flags *f)
{
	if (**s == '-')
		f->minus = 1;
	else if (**s == '+')
		f->plus = 1;
	else if (**s == '0')
		f->zero = 1;
	else if (**s == ' ')
		f->space = 1;
	else if (**s == '#')
		f->hash = 1;
	else
		return (0);
	(*s)++;
	return (1);
}

static size_t	handle_width(char **s, t_flags *f, va_list *args)
{
	int	width;

	if ((width = ft_atoi(*s)) > 0 || **s == '*')
	{
		width = (**s == '*') ? va_arg(*args, int) : width;
		if (width < 0)
			f->minus = 1;
		f->width = (width < 0) ? (-width) : width;
		width = (**s == '*') ? 1 : width;
		while (width > 0 && ((*s)++))
			width /= 10;
		return (1);
	}
	return (0);
}

static size_t	handle_precision(char **s, t_flags *f, va_list *args)
{
	int		precision;

	if (**s == '.')
	{
		(*s)++;
		f->precision = 0;
		if (((ft_isdigit(**s)) && (precision = ft_atoi(*s)) >= 0) || **s == '*')
		{
			precision = (**s == '*') ? va_arg(*args, int) : precision;
			f->precision = (precision > -1) ? precision : -1;
			if (**s == '*')
				precision = 1;
			else if (precision == 0)
				(*s)++;
			while (precision > 0 && (*s)++)
				precision /= 10;
		}
		return (1);
	}
	return (0);
}

static size_t	handle_type(char **s, t_flags *f)
{
	if ((**s == 'l' && *(*s + 1) == 'l') || (**s == 'h' && *(*s + 1) == 'h'))
	{
		if ((**s == 'l' && *(*s + 1) == 'l'))
			f->type = (TYPE_LL > f->type) ? TYPE_LL : f->type;
		else if ((**s == 'h' && *(*s + 1) == 'h'))
			f->type = (TYPE_HH > f->type) ? TYPE_HH : f->type;
		(*s) += 2;
	}
	else if (**s == 'h' || **s == 'l' || **s == 'j' || **s == 'z')
	{
		if (**s == 'h')
			f->type = (TYPE_H > f->type) ? TYPE_H : f->type;
		else if (**s == 'l')
			f->type = (TYPE_L > f->type) ? TYPE_L : f->type;
		else if (**s == 'j')
			f->type = (TYPE_J > f->type) ? TYPE_J : f->type;
		else if (**s == 'z')
			f->type = (TYPE_Z > f->type) ? TYPE_Z : f->type;
		(*s)++;
	}
	else
		return (0);
	return (1);
}

size_t			handle_arg(char **s, va_list *args, t_flags *f)
{
	int	found;

	found = 0;
	while (handle_format(s, f)
			|| handle_width(s, f, args)
			|| handle_precision(s, f, args)
			|| handle_type(s, f))
		found = 1;
	return (found);
}
