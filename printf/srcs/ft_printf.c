/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 01:14:26 by asansyzb          #+#    #+#             */
/*   Updated: 2019/02/13 01:50:28 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	handle_format(char **s, va_list *args, t_flags *f)
{
	int	found;

	init_flags(f);
	while (**s)
	{
		found = 0;
		if (handle_arg(s, args, f))
			found = 1;
		if (ft_isalpha(**s) || **s == '%')
			return (print_arg(s, f, args));
		else if (!found)
			return (0);
	}
	return (0);
}

t_clr	g_clrs[COLOR_CNT] = {
	{"{eoc}", "\033[0m"}, {"{black}", "\033[0;30m"}, {"{red}", "\033[0;31m"},
	{"{green}", "\033[0;32m"}, {"{orange}", "\033[0;33m"},
	{"{blue}", "\033[0;34m"}, {"{purple}", "\033[0;35m"},
	{"{cyan}", "\033[0;36m"}, {"{yellow}", "\033[1;33m"},
	{"{light_purple}", "\033[1;35m"}, {"{white}", "\033[1;37m"}
};

static size_t	handle_color(char **s)
{
	int		i;
	size_t	len;
	size_t	s_len;

	i = -1;
	len = 0;
	s_len = ft_strlen(*s);
	while (++i < COLOR_CNT)
	{
		if (!ft_strncmp(*s, g_clrs[i].name, ft_strlen(g_clrs[i].name)))
		{
			len += write(1, g_clrs[i].code, ft_strlen(g_clrs[i].code));
			*s += (int)ft_strlen(g_clrs[i].name);
			i--;
		}
	}
	return (len);
}

static size_t	write_until_percentage(char **s)
{
	char	*ends;
	char	*clr;
	size_t	res;
	size_t	clr_size;
	size_t	clr_cnt;

	res = 0;
	clr_cnt = words_count(*s, '{');
	clr_size = 0;
	while (clr_cnt--)
	{
		clr = ft_strchr(*s, '{');
		ends = ft_strchr(*s, '%');
		if (clr && (clr < ends || !ends))
		{
			write(1, *s, (size_t)(clr - *s));
			clr_size += (clr - *s);
			*s += (clr - *s);
			clr_size += handle_color(s);
		}
	}
	res += (ends) ? (ends - *s) : ft_strlen(*s);
	write(1, *s, res);
	*s += res;
	return (res + clr_size);
}

static size_t	process(va_list *args, const char *fmt)
{
	char	*ptr;
	t_flags f;

	ptr = (char*)fmt;
	f.bytes = 0;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			f.bytes += handle_format(&ptr, args, &f);
		}
		else
			f.bytes += write_until_percentage(&ptr);
	}
	return (f.bytes);
}

int				ft_printf(const char *fmt, ...)
{
	va_list args;
	int		res;

	res = 0;
	if (fmt)
	{
		va_start(args, fmt);
		res = process(&args, fmt);
		va_end(args);
	}
	return (res);
}
