/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 23:42:25 by asansyzb          #+#    #+#             */
/*   Updated: 2018/12/11 23:47:14 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <pthread.h>
# define WIDTH 768
# define HEIGHT 768
# define NB_T 12

typedef struct	s_image
{
	void	*image;
	char	*ptr;
	int		bpp;
	int		stride;
	int		endian;
}				t_image;

typedef struct	s_wind
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	re_factor;
	double	im_factor;
	int		color;
	int		type;
	int		freeze;
	int		max_iter;
	double	zoom;
	double	mouse_re;
	double	mouse_im;
	int		x;
	int		y;
	int		status;
	int		zoom_factor;
	t_image	*image;
	void	*m_p;
	void	*w_p;
}				t_wind;

typedef struct	s_pthread
{
	t_wind	*w;
	int		x;
	int		y;
	int		ti;
}				t_pthread;

typedef	struct	s_point
{
	double	z_re2;
	double	z_im2;
	double	z_im;
	double	z_re;
	double	c_im;
	double	c_re;
}				t_point;

void			jcubic(t_wind *w, int x, int y, t_point *p);
void			mcubic(t_wind *w, int x, int y, t_point *p);
void			julia(t_wind *w, int x, int y, t_point *p);
void			mandelbrot(t_wind *w, int x, int y, t_point *p);
void			burningship(t_wind *w, int x, int y, t_point *p);
void			image_set_pixel(t_image *image, int x, int y, int color);
void			draw(t_wind *w);
t_image			*del_image(t_wind *w, t_image *img);
void			image_set_pixel(t_image *image, int x, int y, int color);
t_image			*new_image(t_wind *w);
int				hook_keydown(int key, int x, int y, t_wind *w);
int				mouse_move(int x, int y, t_wind *w);
int				loop_hook(t_wind *w);
double			interpolate(double start, double end, double interpolation);
double			ft_abs(double x);
void			die(char *s);
int				key_hook(int key, t_wind *w);
void			move_camera(int key, t_wind *w);
int				coloring(int k, int a, int b, int c);

#endif
