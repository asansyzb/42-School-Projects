/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:15:10 by asansyzb          #+#    #+#             */
/*   Updated: 2018/11/27 18:15:54 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	red_color(int c, int max)
{
	float	p;

	p = (float)c / (float)max;
	if (p == 1)
		return (R100);
	else if (p >= 0.8 && p < 1)
		return (R80);
	else if (p >= 0.6 && p < 0.8)
		return (R60);
	else if (p >= 0.4 && p < 0.6)
		return (R40);
	else if (p >= 0.2 && p < 0.4)
		return (R20);
	return (R10);
}

static int	blue_color(int c, int min)
{
	float	p;

	p = c / min;
	if (p == 1)
		return (B100);
	else if (p >= 0.8 && p < 1)
		return (B80);
	else if (p >= 0.6 && p < 0.8)
		return (B60);
	else if (p >= 0.4 && p < 0.6)
		return (B40);
	else if (p >= 0.2 && p < 0.4)
		return (B20);
	return (B10);
}

int			set_color(int c, int min, int max)
{
	int	color;

	if (c > 0)
		color = red_color(c, max);
	else if (c < 0)
		color = blue_color(c, min);
	else
		color = 0xffffff;
	return (color);
}
