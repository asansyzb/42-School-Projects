/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:33:41 by vmuradia          #+#    #+#             */
/*   Updated: 2019/01/03 20:51:36 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		check_move(t_game *game, double x, double y)
{
	if (game->map[(int)(x - 0.1)][(int)y] == 0 &&
		game->map[(int)(x + 0.1)][(int)y] == 0 &&
		game->map[(int)(x)][(int)(y)] == 0 &&
		game->map[(int)(x)][(int)(y + 0.1)] == 0 &&
		game->map[(int)(x)][(int)(y - 0.1)] == 0 &&
		game->map[(int)(x - 0.1)][(int)(y + 0.1)] == 0 &&
		game->map[(int)(x - 0.1)][(int)(y - 0.1)] == 0 &&
		game->map[(int)(x + 0.1)][(int)(y + 0.1)] == 0 &&
		game->map[(int)(x + 0.1)][(int)(y - 0.1)] == 0)
		return (1);
	return (0);
}

void	move_forward(t_game *game)
{
	double	x;
	double	y;

	x = game->pos_x + game->dir_x * game->movespeed;
	y = game->pos_y + game->dir_y * game->movespeed;
	if ((x < game->map_height - 1 && (x) > 0) &&
		(game->pos_y < game->map_width - 1 && game->pos_y > 0) &&
		check_move(game, x, game->pos_y))
		game->pos_x += game->dir_x * game->movespeed;
	if ((game->pos_x < game->map_height - 1 && game->pos_x > 0) &&
		(y < game->map_width - 1 && y > 0) &&
		check_move(game, game->pos_x, y))
		game->pos_y += game->dir_y * game->movespeed;
}

void	go_back(t_game *game)
{
	double	x;
	double	y;

	x = game->pos_x - game->dir_x * game->movespeed;
	y = game->pos_y - game->dir_y * game->movespeed;
	if ((x > 0 && x < game->map_height - 1)
		&& (game->pos_y > 0 && game->pos_y < game->map_width - 1) &&
		check_move(game, x, game->pos_y))
		game->pos_x -= game->dir_x * game->movespeed;
	if ((game->pos_x < game->map_height - 1 && game->pos_x > 0)
		&& (y > 0 && y < game->map_width - 1) &&
		check_move(game, game->pos_x, y))
		game->pos_y -= game->dir_y * game->movespeed;
}

void	lean_left(t_game *game)
{
	double	x;
	double	y;

	x = game->pos_x - game->plane_x * game->movespeed;
	y = game->pos_y - game->plane_y * game->movespeed;
	if ((x > 0 && x < game->map_height - 1) &&
		(game->pos_y > 0 && game->pos_y < game->map_width - 1) &&
		check_move(game, x, game->pos_y))
		game->pos_x -= game->plane_x * game->movespeed;
	if ((game->pos_x > 0 && game->pos_x < game->map_height - 1) &&
		(y > 0 && y < game->map_width - 1) &&
		check_move(game, game->pos_x, y))
		game->pos_y -= game->plane_y * game->movespeed;
}

void	lean_right(t_game *game)
{
	double	x;
	double	y;

	x = game->pos_x + game->plane_x * game->movespeed;
	y = game->pos_y + game->plane_y * game->movespeed;
	if ((x > 0 && x < game->map_height - 1) && (game->pos_y > 0 &&
		game->pos_y < game->map_width - 1) &&
		check_move(game, x, game->pos_y))
		game->pos_x += game->plane_x * game->movespeed;
	if ((game->pos_x > 0 && game->pos_x < game->map_height - 1) &&
		(y > 0 && y < game->map_width - 1) &&
		check_move(game, game->pos_x, y))
		game->pos_y += game->plane_y * game->movespeed;
}
