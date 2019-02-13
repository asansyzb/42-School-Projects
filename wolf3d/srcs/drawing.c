/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 19:02:39 by vmuradia          #+#    #+#             */
/*   Updated: 2018/12/28 17:21:30 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	calc_textures(t_game *game, int y, int x, t_point *p)
{
	p->c_dist = SCR_HEIGHT / (2.0 * y - SCR_HEIGHT);
	p->weight = (p->c_dist - p->dist_play) / (p->dist_wall -
		p->dist_play);
	p->fl_x = p->weight * p->floor_x + (1.0 - p->weight) * game->pos_x;
	p->fl_y = p->weight * p->floor_y + (1.0 - p->weight) * game->pos_y;
	p->floortex_x = (int)(p->fl_x * game->texture[0]->width) %
	game->texture[0]->width;
	p->floortex_y = (int)(p->fl_y * game->texture[0]->height) %
	game->texture[0]->height;
	p->col = (*(int*)&game->texture[0]->ptr[((p->floortex_x *
	(game->texture[0]->bpp >> 3) + p->floortex_y *
	game->texture[0]->stride))]);
	image_set_pixel(game->img, x, y, p->col);
}

void	sky(t_game *game, double wall_x, int x)
{
	int		y;
	t_point *p;

	p = (t_point*)malloc(sizeof(t_point));
	game->buffer[x] = game->pwalld;
	floory(game, p, wall_x);
	p->dist_wall = game->pwalld;
	p->dist_play = 0.0;
	if (game->draw_end < 0)
		game->draw_end = SCR_HEIGHT;
	y = game->draw_end;
	while (++y < SCR_HEIGHT)
		calc_textures(game, y, x, p);
	free(p);
}

void	dda(t_game *game, int *n)
{
	while (game->hit == 0)
	{
		if (game->sidedistx < game->sidedisty)
		{
			game->sidedistx += game->deldistx;
			game->map_x += game->step_x;
			game->side = 0;
		}
		else
		{
			game->sidedisty += game->deldisty;
			game->map_y += game->step_y;
			game->side = 1;
		}
		if (game->map[game->map_x][game->map_y] > 0)
		{
			game->hit = 1;
			*n = game->map[game->map_x][game->map_y] % 5;
			*n = (*n == 0) ? 1 : *n;
		}
	}
}

void	calc_wall(t_game *game, double *wall_x)
{
	if (game->side == 0)
		game->pwalld = ((double)game->map_x - game->pos_x +
			((1 - game->step_x) >> 1)) / game->ray_dirx;
	else
		game->pwalld = ((double)game->map_y - game->pos_y +
			((1 - game->step_y) >> 1)) / game->ray_diry;
	game->line_h = (int)(SCR_HEIGHT / game->pwalld);
	game->draw_st = -((game->line_h) >> 1) + (SCR_HEIGHT >> 1);
	if (game->draw_st < 0)
		game->draw_st = 0;
	game->draw_end = (game->line_h >> 1) + (SCR_HEIGHT >> 1);
	if (game->draw_end >= SCR_HEIGHT)
		game->draw_end = SCR_HEIGHT - 1;
	if (game->side == 0)
		*wall_x = game->pos_y + game->pwalld * game->ray_diry;
	else
		*wall_x = game->pos_x + game->pwalld * game->ray_dirx;
	*wall_x -= floor(*wall_x);
}

void	draw_wall(t_game *game, int *n, double wall_x, int x)
{
	int y;
	int tex_x;
	int	d;
	int	tex_y;
	int	col;

	tex_x = (int)(wall_x * (double)(game->texture[*n]->width));
	if (game->side == 0 && game->ray_dirx > 0)
		tex_x = game->texture[*n]->width - tex_x - 1;
	if (game->side == 1 && game->ray_diry < 0)
		tex_x = game->texture[*n]->width - tex_x - 1;
	y = game->draw_st - 1;
	while (++y < game->draw_end)
	{
		d = (y << 8) - (SCR_HEIGHT << 7) + (game->line_h << 7);
		tex_y = ((d * game->texture[*n]->height) / game->line_h) >> 8;
		col = *(int*)&game->texture[*n]->ptr[game->texture[*n]->stride *
		tex_y + tex_x * (game->texture[*n]->bpp >> 3)];
		if (game->side == 1)
			col = (col >> 1) & 8355711;
		image_set_pixel(game->img, x, y, col);
	}
}
