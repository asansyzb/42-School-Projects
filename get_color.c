/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:28:43 by asansyzb          #+#    #+#             */
/*   Updated: 2018/11/27 20:29:25 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int			get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + (percentage * end)));
}

int			get_color(t_point *t)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (t->dx > t->dy)
		percentage = percent(t->x1, t->x2, t->x);
	else
		percentage = percent(t->y1, t->y2, t->y);
	red = get_light((t->z1 >> 16) & 0xFF, (t->z2 >> 16) & 0xFF, percentage);
	green = get_light((t->z1 >> 8) & 0xFF, (t->z2 >> 8) & 0xFF, percentage);
	blue = get_light(t->z1 & 0xFF, t->z2 & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
