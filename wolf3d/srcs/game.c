/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 21:48:18 by vmuradia          #+#    #+#             */
/*   Updated: 2019/01/03 20:14:47 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		game_init(t_game *game, int x)
{
	game->movespeed = (1 / game->frame_time) * ((game->accel_on) ? 16.0 : 10.0);
	game->rot_speed = (1 / game->frame_time) * ((game->accel_on) ? 10.0 : 6.0);
	game->camera_x = (x << 1) / (double)SCR_WIDTH - 1;
	game->ray_dirx = game->dir_x + game->plane_x * game->camera_x;
	game->ray_diry = game->dir_y + game->plane_y * game->camera_x;
	game->map_x = (int)game->pos_x;
	game->map_y = (int)game->pos_y;
	game->deldistx = fabs(1 / game->ray_dirx);
	game->deldisty = fabs(1 / game->ray_diry);
	game->hit = 0;
	if (game->accel_on && time(NULL) - game->accel_t >= 5)
	{
		game->accel_on = 0;
		game->accel_cd_t = time(NULL);
	}
}

void		moving(t_game *game)
{
	if (game->ray_dirx < 0)
	{
		game->step_x = -1;
		game->sidedistx = (game->pos_x - game->map_x) * game->deldistx;
	}
	else
	{
		game->step_x = 1;
		game->sidedistx = (game->map_x + 1.0 - game->pos_x) * game->deldistx;
	}
	if (game->ray_diry < 0)
	{
		game->step_y = -1;
		game->sidedisty = (game->pos_y - game->map_y) * game->deldisty;
	}
	else
	{
		game->step_y = 1;
		game->sidedisty = (game->map_y + 1.0 - game->pos_y) * game->deldisty;
	}
}

void		draw_speed(t_game *g)
{
	int		x;
	int		y;
	int		percent;
	time_t	now;

	y = -1;
	now = time(NULL);
	if (g->accel_on)
		percent = 200 - (now - g->accel_t) * 100 / 2.5;
	else
		percent = (now - g->accel_cd_t) * 100 / 2.5;
	percent = (percent > 200) ? 200 : percent;
	while (++y < 50)
	{
		x = 200;
		while (--x > 0)
		{
			if (y < 3 || y > 46 || x < 3 || x > 196)
				image_set_pixel(g->img, 20 + x, SCR_HEIGHT - 70 + y, 0xffffff);
			else if (x < percent)
				image_set_pixel(g->img, 20 + x, SCR_HEIGHT - 70 + y, 0xffff00);
		}
	}
}

void		draw_skybox(t_game *g)
{
	int	x;
	int	y;
	int	color;

	y = -1;
	while (++y < SCR_HEIGHT / 2)
	{
		x = 0;
		while (++x < SCR_WIDTH)
		{
			color = (*(int*)&g->texture[6]->ptr[((x *
				(g->texture[6]->bpp >> 3) + y *
				g->texture[6]->stride))]);
			image_set_pixel(g->img, x, y, color);
		}
	}
}

void		wolf(t_game *g)
{
	int			n;
	int			x;
	double		wall_x;

	x = -1;
	g->start_t = clock();
	draw_skybox(g);
	while (++x < SCR_WIDTH)
	{
		game_init(g, x);
		moving(g);
		dda(g, &n);
		calc_wall(g, &wall_x);
		draw_wall(g, &n, wall_x, x);
		sky(g, wall_x, x);
	}
	draw_sprite(g, g->sprite);
	draw_speed(g);
	draw_minimap(g);
	g->end_t = clock();
	g->frame_time = CLOCKS_PER_SEC / (double)(g->end_t - g->start_t);
}
