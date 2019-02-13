/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:37:10 by asansyzb          #+#    #+#             */
/*   Updated: 2018/11/27 18:13:09 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		plot_line_low(t_wind *w, t_point *p)
{
	p->yi = 1;
	p->dx = p->x2 - p->x1;
	p->dy = p->y2 - p->y1;
	if (p->dy < 0)
	{
		p->yi = -1;
		p->dy = -p->dy;
	}
	p->d = 2 * p->dy - p->dx;
	p->y = p->y1;
	p->x = p->x1;
	while (p->x < p->x2)
	{
		mlx_pixel_put(w->m_p, w->w_p, w->p_x - w->z + p->x,
			w->p_y - w->z + p->y, get_color(p));
		if (p->d > 0)
		{
			p->y += p->yi;
			p->d -= 2 * p->dx;
		}
		p->d += 2 * p->dy;
		p->x++;
	}
}

static void		plot_line_high(t_wind *w, t_point *p)
{
	p->xi = 1;
	p->dx = p->x2 - p->x1;
	p->dy = p->y2 - p->y1;
	if (p->dx < 0)
	{
		p->xi = -1;
		p->dx = -p->dx;
	}
	p->d = 2 * p->dx - p->dy;
	p->x = p->x1;
	p->y = p->y1;
	while (p->y < p->y2)
	{
		mlx_pixel_put(w->m_p, w->w_p, w->p_x - w->z + p->x,
			w->p_y - w->z + p->y, get_color(p));
		if (p->d > 0)
		{
			p->x += p->xi;
			p->d -= 2 * p->dy;
		}
		p->d += 2 * p->dx;
		p->y++;
	}
}

static void		init_point(t_point **p, t_vect *a, t_vect *b, int i)
{
	if (a == b)
	{
		(*p)->x1 = a->line_x[i - 1];
		(*p)->x2 = b->line_x[i];
		(*p)->y1 = a->line_y[i - 1];
		(*p)->y2 = b->line_y[i];
		(*p)->z1 = a->line[i - 1];
		(*p)->z2 = b->line[i];
	}
	else
	{
		(*p)->x1 = a->line_x[i];
		(*p)->x2 = b->line_x[i];
		(*p)->y1 = a->line_y[i];
		(*p)->y2 = b->line_y[i];
		(*p)->z1 = a->line[i];
		(*p)->z2 = b->line[i];
	}
}

static void		plot_line(t_wind *w, t_point *p)
{
	p->z1 = set_color(p->z1, w->min, w->max);
	p->z2 = set_color(p->z2, w->min, w->max);
	if (ft_abs(p->y2 - p->y1) < ft_abs(p->x2 - p->x1))
	{
		if (p->x1 > p->x2)
			ft_swap_points(&p);
		plot_line_low(w, p);
	}
	else
	{
		if (p->y1 > p->y2)
			ft_swap_points(&p);
		plot_line_high(w, p);
	}
}

void			draw(t_wind *w)
{
	int		i;
	t_list	*tmp;
	t_point	*p;
	t_vect	*t;
	t_vect	*prev;

	tmp = w->lst;
	prev = NULL;
	p = (t_point*)ft_memalloc(sizeof(t_point));
	while (tmp)
	{
		i = -1;
		t = (t_vect*)tmp->content;
		while (++i < t->w)
		{
			(i > 0) ? init_point(&p, t, t, i) : ft_bzero(p, sizeof(t_point));
			plot_line(w, p);
			(prev != NULL) ? init_point(&p, prev, t, i) :
							ft_bzero(p, sizeof(t_point));
			plot_line(w, p);
		}
		prev = t;
		tmp = tmp->next;
	}
	ft_memdel((void**)&p);
}
