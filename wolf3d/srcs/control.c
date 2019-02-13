/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:14:39 by vmuradia          #+#    #+#             */
/*   Updated: 2019/01/03 20:54:13 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	camera_right(t_game *game)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = game->dir_x;
	old_plane_x = game->plane_x;
	game->dir_x = game->dir_x * cos(game->rot_speed) + game->dir_y *
	sin(game->rot_speed);
	game->dir_y = -old_dir_x * sin(game->rot_speed) + game->dir_y *
	cos(game->rot_speed);
	game->plane_x = game->plane_x * cos(game->rot_speed) + game->plane_y *
	sin(game->rot_speed);
	game->plane_y = -old_plane_x * sin(game->rot_speed) + game->plane_y *
	cos(game->rot_speed);
}

static void	camera_left(t_game *game)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = game->dir_x;
	old_plane_x = game->plane_x;
	game->dir_x = game->dir_x * cos(game->rot_speed) - game->dir_y *
	sin(game->rot_speed);
	game->dir_y = old_dir_x * sin(game->rot_speed) + game->dir_y *
	cos(game->rot_speed);
	game->plane_x = game->plane_x * cos(game->rot_speed) - game->plane_y *
	sin(game->rot_speed);
	game->plane_y = old_plane_x * sin(game->rot_speed) + game->plane_y *
	cos(game->rot_speed);
}

static void	menu_keys(int key, t_game *game)
{
	if (key == 126 || key == 125)
	{
		game->pointer = !game->pointer;
		mlx_clear_window(game->m_p, game->w_p);
		show_menu(game);
	}
	else if (key == 36)
	{
		if (game->pointer)
		{
			game->update_t = time(NULL);
			game->accel_cd_t = time(NULL);
			game->menu = 0;
		}
		else
			exit(0);
	}
}

static void	game_keys(int key, t_game *game)
{
	if (key == 13)
		move_forward(game);
	else if (key == 1)
		go_back(game);
	else if (key == 0)
		lean_left(game);
	else if (key == 2)
		lean_right(game);
	else if (key == 124)
		camera_right(game);
	else if (key == 123)
		camera_left(game);
	else if (key == 257 && (time(NULL) - game->accel_cd_t >= 5)
		&& !game->accel_on)
	{
		game->accel_on = 1;
		game->accel_t = time(NULL);
	}
	game->status = 1;
}

int			keys(int key, t_game *game)
{
	if (key == 53)
		exit(0);
	if (game->menu)
		menu_keys(key, game);
	else if (!game->menu)
		game_keys(key, game);
	return (0);
}
