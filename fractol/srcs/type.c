/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 01:59:43 by asansyzb          #+#    #+#             */
/*   Updated: 2018/12/16 01:59:46 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void		burningship(t_wind *w, int x, int y, t_point *p)
{
	int		k;

	p->c_re = w->min_re + x * w->re_factor;
	k = -1;
	p->z_re = p->c_re;
	p->z_im = p->c_im;
	while (++k < w->max_iter)
	{
		p->z_re2 = p->z_re * p->z_re;
		p->z_im2 = p->z_im * p->z_im;
		if (p->z_re2 + p->z_im2 > 4)
			break ;
		p->z_im = ft_abs(2 * p->z_re * p->z_im) - p->c_im;
		p->z_re = ft_abs(p->z_re2 - p->z_im2 + p->c_re);
	}
	if (k < w->max_iter)
		image_set_pixel(w->image, x, y,
				coloring(k, 21 + w->color, 10 + w->color, 3 + w->color));
}

void		mandelbrot(t_wind *w, int x, int y, t_point *p)
{
	int		k;
	double	q;

	k = -1;
	p->c_re = w->min_re + x * w->re_factor;
	q = (p->c_re - 0.25) * (p->c_re - 0.25) + p->c_im * p->c_im;
	if (q * (q + (p->c_re - 0.25)) >= p->c_im * p->c_im / 4)
	{
		p->z_re = p->c_re;
		p->z_im = p->c_im;
		while (++k < w->max_iter)
		{
			p->z_re2 = p->z_re * p->z_re;
			p->z_im2 = p->z_im * p->z_im;
			if (p->z_re2 + p->z_im2 > 4)
				break ;
			p->z_im = 2 * p->z_re * p->z_im + p->c_im;
			p->z_re = p->z_re2 - p->z_im2 + p->c_re;
		}
		if (k < w->max_iter)
			image_set_pixel(w->image, x, y,
					coloring(k, 21 + w->color, 10 + w->color, 3 + w->color));
	}
}

void		julia(t_wind *w, int x, int y, t_point *p)
{
	int		k;
	double	re;
	double	im;

	p->c_re = w->min_re + x * w->re_factor;
	re = (((double)w->x - (double)(WIDTH >> 2)) / (double)WIDTH);
	im = (((double)w->y - (double)(WIDTH >> 2)) / (double)WIDTH);
	k = -1;
	p->z_re = p->c_re;
	p->z_im = p->c_im;
	while (++k < w->max_iter)
	{
		p->z_re2 = p->z_re * p->z_re;
		p->z_im2 = p->z_im * p->z_im;
		if (p->z_re2 + p->z_im2 > 4)
			break ;
		p->z_im = 2 * p->z_re * p->z_im + im;
		p->z_re = p->z_re2 - p->z_im2 - re;
	}
	if (k < w->max_iter)
		image_set_pixel(w->image, x, y,
				coloring(k, 21 + w->color, 10 + w->color, 3 + w->color));
}

void		jcubic(t_wind *w, int x, int y, t_point *p)
{
	int		k;
	double	re;
	double	im;
	double	tmp;

	p->c_re = w->min_re + x * w->re_factor;
	re = (((double)w->x - (double)(WIDTH >> 2)) / (double)WIDTH);
	im = (((double)w->y - (double)(WIDTH >> 2)) / (double)WIDTH);
	k = -1;
	p->z_re = p->c_re;
	p->z_im = p->c_im;
	while (++k < w->max_iter)
	{
		p->z_re2 = p->z_re * p->z_re;
		p->z_im2 = p->z_im * p->z_im;
		if (p->z_re2 + p->z_im2 > 4)
			break ;
		tmp = (p->z_re2 * p->z_re) - (p->z_im2 * p->z_re)
						- (2 * p->z_re * p->z_im2) + re;
		p->z_im = 3 * p->z_re2 * p->z_im - p->z_im2 * p->z_im + im;
		p->z_re = tmp;
	}
	if (k < w->max_iter)
		image_set_pixel(w->image, x, y,
				coloring(k, 21 + w->color, 10 + w->color, 3 + w->color));
}

void		mcubic(t_wind *w, int x, int y, t_point *p)
{
	int		k;
	double	tmp;

	p->c_re = w->min_re + x * w->re_factor;
	k = -1;
	p->z_re = p->c_re;
	p->z_im = p->c_im;
	while (++k < w->max_iter)
	{
		p->z_re2 = p->z_re * p->z_re;
		p->z_im2 = p->z_im * p->z_im;
		if (p->z_re2 + p->z_im2 > 4)
			break ;
		tmp = (p->z_re2 * p->z_re) - (p->z_im2 * p->z_re)
						- (2 * p->z_re * p->z_im2) + p->c_re;
		p->z_im = 3 * p->z_re2 * p->z_im - p->z_im2 * p->z_im + p->c_im;
		p->z_re = tmp;
	}
	if (k < w->max_iter)
		image_set_pixel(w->image, x, y,
				coloring(k, 21 + w->color, 10 + w->color, 3 + w->color));
}
