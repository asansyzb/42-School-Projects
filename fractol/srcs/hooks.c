/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 02:29:14 by asansyzb          #+#    #+#             */
/*   Updated: 2018/12/16 02:29:17 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int		hook_keydown(int key, int x, int y, t_wind *w)
{
	double	interpolation;

	if (key == 1)
		w->max_iter += 50;
	else if (key == 2)
		w->max_iter -= 50;
	if (key == 4 || key == 5)
	{
		w->mouse_re = (double)x / ((WIDTH - 1) /
						(w->max_re - w->min_re)) + w->min_re;
		w->mouse_im = (double)y / ((HEIGHT - 1) /
						(w->max_im - w->min_im)) + w->min_im;
		w->zoom = (key == 4) ? 1.05 : (1.0 / 1.05);
		interpolation = 1.0 / w->zoom;
		w->min_re = interpolate(w->mouse_re, w->min_re, interpolation);
		w->min_im = interpolate(w->mouse_im, w->min_im, interpolation);
		w->max_re = interpolate(w->mouse_re, w->max_re, interpolation);
		w->max_im = interpolate(w->mouse_im, w->max_im, interpolation);
		w->re_factor = (w->max_re - w->min_re) / (WIDTH - 1);
		w->im_factor = (w->max_im - w->min_im) / (HEIGHT - 1);
		w->zoom_factor += 1;
	}
	w->status = 1;
	return (1);
}

int		mouse_move(int x, int y, t_wind *w)
{
	if (x < WIDTH && y < HEIGHT && !w->freeze)
	{
		w->x = x;
		w->y = y;
		w->status = 1;
	}
	return (1);
}

int		key_hook(int key, t_wind *w)
{
	if (key == 257)
	{
		w->color += 1;
		w->status = 1;
	}
	else if (key == 13 || key == 0 || key == 1 || key == 2)
		move_camera(key, w);
	else if (key == 53)
	{
		if (w->image)
			mlx_destroy_image(w->m_p, w->image->image);
		free(w->image);
		free(w->m_p);
		free(w->w_p);
		free(w);
		exit(0);
	}
	else if (key == 8 && (w->type == 2 || w->type == 5))
		w->freeze = !w->freeze;
	return (0);
}

int		loop_hook(t_wind *w)
{
	if (w->status)
	{
		if (w->image)
			del_image(w, w->image);
		w->image = new_image(w);
		draw(w);
		mlx_put_image_to_window(w->m_p, w->w_p, w->image->image, 0, 0);
	}
	w->status = 0;
	return (0);
}
