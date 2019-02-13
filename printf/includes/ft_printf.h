/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 05:17:05 by asansyzb          #+#    #+#             */
/*   Updated: 2019/02/13 01:50:57 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include "stdarg.h"
# include "wchar.h"

# define FLAGS "#0+- "
# define HEX "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"
# define OCTAL "01234567"
# define DECIMAL "0123456789"
# define TYPE_HH 1
# define TYPE_H 2
# define TYPE_L 3
# define TYPE_LL 4
# define TYPE_J 5
# define TYPE_Z 6
# define COLOR_CNT 11

typedef struct	s_flags
{
	int		width;
	int		plus;
	int		minus;
	int		type;
	int		space;
	int		hash;
	int		zero;
	int		precision;
	int		i;
	int		bytes;
	char	format;
	char	padding_char;
	char	*prefix;
	char	*base;
	char	buff[BUFF_SIZE + 1];
}				t_flags;

typedef struct	s_clr
{
	char	*name;
	char	*code;
}				t_clr;

char			*ft_ullitoa_base(unsigned long long int n, char *base);
char			*ft_llitoa_base(long long int n, char *base);
size_t			handle_arg(char **s, va_list *args, t_flags *f);
void			ft_putstr_tobuf(char *src, t_flags *f);
void			ft_putnchar_tobuf(char c, t_flags *f, int len);
void			init_flags(t_flags *f);
void			handle_flags(t_flags *f, char *p);
size_t			fmt_putnbr(char *p, t_flags *f);
size_t			fmt_putchar(char c, t_flags *f);
size_t			fmt_putptr(char *p, t_flags *f);
size_t			print_arg(char **s, t_flags *f, va_list *args);
char			*convert_nbr(void *p, t_flags *f);
size_t			print_arg_float(va_list *args, t_flags *f);
size_t			print_arg_lint(va_list *args, t_flags *f);
size_t			print_arg_int(va_list *args, t_flags *f);
size_t			print_arg_uint(va_list *args, t_flags *f);
size_t			ft_strwlen(wchar_t *s);
char			*ft_strwdup(wchar_t *s);
int				ft_printf(const char *fmt, ...);
#endif
