/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:37:50 by asansyzb          #+#    #+#             */
/*   Updated: 2018/11/27 18:14:59 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define R100 0x800000
# define R80 0xff0000
# define R60 0xff6600
# define R40 0xff9966
# define R20 0xffcc99
# define R10 0xffffcc
# define B100 0x0000cc
# define B80 0x0000ff
# define B60 0x0066ff
# define B40 0x3399ff
# define B20 0x66ccff
# define B10 0xccffff

typedef struct	s_point
{
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		z1;
	int		z2;
	int		dx;
	int		dy;
	int		x;
	int		y;
	int		yi;
	int		xi;
	int		d;
}				t_point;

typedef struct	s_wind
{
	int		w;
	int		h;
	int		cnt;
	int		min;
	int		max;
	int		coef;
	double	a_x;
	double	a_y;
	int		p_x;
	int		p_y;
	int		x;
	int		y;
	int		z;
	void	*m_p;
	void	*w_p;
	t_list	*lst;
}				t_wind;

typedef struct	s_vect
{
	int		*line_x;
	int		*line_y;
	int		*line;
	int		w;
}				t_vect;

int				set_color(int c, int min, int max);
t_list			*reader(int fd, int *cnt);
void			draw(t_wind *w);
void			free_lst(t_list **list);
void			ft_swap(int *a, int *b);
int				get_color(t_point *t);
void			ft_swap_points(t_point **p);
void			get_points(t_wind *w);
void			find_min_max(int n, int *min, int *max);
int				ft_abs(int a);
int				get_color(t_point *t);
void			malloc_lines(t_vect **t);
int				hook_keydown(int key, t_wind *w);
void			change_landschaft(int key, t_wind *w);
void			rotate(int key, t_wind *w);
void			zoom(int key, t_wind *w);
void			move(int key, t_wind *w);

#endif
