/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 01:57:17 by asansyzb          #+#    #+#             */
/*   Updated: 2018/12/16 01:57:19 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

static void			draw_type(t_wind *w, int x, int y, t_point *p)
{
	if (w->type == 1)
		mandelbrot(w, x, y, p);
	else if (w->type == 2)
		julia(w, x, y, p);
	else if (w->type == 3)
		burningship(w, x, y, p);
	else if (w->type == 4)
		mcubic(w, x, y, p);
	else if (w->type == 5)
		jcubic(w, x, y, p);
}

static void			calc(void *thread)
{
	t_pthread	*t;
	t_wind		*w;
	t_point		*p;
	int			x;
	int			y;

	if (!(p = (t_point *)malloc(sizeof(t_point))))
		die("something went wrong in calc :c");
	t = (t_pthread *)thread;
	w = t->w;
	y = ((HEIGHT / NB_T) * t->ti) - 1;
	while (++y < (HEIGHT / NB_T) * (t->ti + 1))
	{
		x = -1;
		p->c_im = w->max_im - y * w->im_factor;
		while (++x < WIDTH)
		{
			draw_type(w, x, y, p);
		}
	}
	free(p);
	free(thread);
}

static pthread_t	handle_threads(t_wind *w, int i)
{
	pthread_t	pthread;
	t_pthread	*t;
	void		*f;

	if (!(t = (t_pthread *)malloc(sizeof(t_pthread))))
		exit(0);
	t->w = w;
	t->ti = i;
	f = (void*)calc;
	pthread_create(&pthread, NULL, f, t);
	return (pthread);
}

void				draw(t_wind *w)
{
	int			i;
	pthread_t	x[NB_T];

	i = -1;
	while (++i < NB_T)
		x[i] = handle_threads(w, i);
	i = -1;
	while (++i < NB_T)
		pthread_join(x[i], NULL);
	mlx_put_image_to_window(w->m_p, w->w_p, w->image->image, 0, 0);
}
