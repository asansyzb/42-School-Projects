/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 02:30:41 by asansyzb          #+#    #+#             */
/*   Updated: 2018/12/16 02:30:44 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

double	ft_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	die(char *s)
{
	ft_putstr_fd(s, 2);
	exit(-1);
}

void	move_camera(int key, t_wind *w)
{
	int	tmp;

	tmp = w->min_im;
	if (key == 13)
	{
		w->min_im -= (w->max_re - tmp) / (WIDTH) / (w->zoom_factor >> 2);
		w->max_im -= (w->max_re - tmp) / (WIDTH) / (w->zoom_factor >> 2);
	}
	else if (key == 1)
	{
		w->min_im += (w->max_re - tmp) / (WIDTH) / (w->zoom_factor >> 2);
		w->max_im += (w->max_re - tmp) / (WIDTH) / (w->zoom_factor >> 2);
	}
	else if (key == 0)
	{
		w->min_re += (w->max_re - tmp) / (WIDTH) / (w->zoom_factor >> 2);
		w->max_re += (w->max_re - tmp) / (WIDTH) / (w->zoom_factor >> 2);
	}
	else if (key == 2)
	{
		w->min_re -= (w->max_re - tmp) / (WIDTH) / (w->zoom_factor >> 2);
		w->max_re -= (w->max_re - tmp) / (WIDTH) / (w->zoom_factor >> 2);
	}
	w->status = 1;
}

int		coloring(int k, int a, int b, int c)
{
	return ((k << a) + (k << b) + (k << c));
}
