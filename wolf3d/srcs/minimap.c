/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 20:08:34 by vmuradia          #+#    #+#             */
/*   Updated: 2019/01/03 20:08:47 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		draw_square(t_game *g, int size, int x, int y)
{
	int	i;
	int	j;

	j = size * 2 + size * y - 1;
	while (++j < size * 2 + (size * (y + 1)))
	{
		i = size * 2 + size * x - 1;
		while (++i < size * 2 + (size * (x + 1)))
		{
			image_set_pixel(g->img, i, j, g->color);
		}
	}
}

void		draw_minimap(t_game *g)
{
	int	x;
	int	y;
	int	size;

	size = SCR_WIDTH / 10 / g->map_width;
	y = -1;
	while (++y < g->map_height)
	{
		x = -1;
		while (++x < g->map_width)
		{
			if (g->map[y][x] > 0)
			{
				g->color = 0x2f4f4f;
				draw_square(g, size, x, y);
			}
		}
	}
	g->color = 0x00ffff;
	draw_square(g, size, g->pos_y, g->pos_x);
}
