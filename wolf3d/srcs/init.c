/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:43:01 by vmuradia          #+#    #+#             */
/*   Updated: 2019/01/03 21:20:15 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** Read the map for the first time for x and y
*/

void	get_info(char *file, t_game *game, int fd, char *line)
{
	int		i;
	int		ret;

	i = -1;
	game->map_width = -1;
	game->map_height = 0;
	fd = open(file, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		game->map_width = (game->map_width == -1) ?
			words_count(line, ' ') : game->map_width;
		game->map_height++;
		if (game->map_width != words_count(line, ' '))
			die("Invalid map");
		free(line);
	}
	close(fd);
	if (ret == -1)
		die("Invalid file");
	if (game->map_height < 4 && game->map_width < 4)
		die("Invalid map");
	game->map = (int**)malloc(sizeof(int*) * game->map_height);
	while (++i < game->map_height)
		game->map[i] = (int*)malloc(sizeof(int) * game->map_width);
}

void	validate_map(t_game *g, int n, int a, int x)
{
	if ((a == 0 || a == g->map_height - 1)
		|| (x == 0 || x == g->map_width - 1))
		g->map[a][x] = 1;
	else
	{
		if (g->map_height / 2 == a && g->map_width / 2 == x)
			g->map[a][x] = 0;
		else
			g->map[a][x] = n;
	}
}

void	read_map(char *file, t_game *game, int fd, char *line)
{
	char	**parsing;
	int		a;
	int		x;

	a = 0;
	x = 0;
	get_info(file, game, fd, line);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) && a < game->map_height)
	{
		parsing = ft_strsplit(line, ' ');
		x = 0;
		while (x < game->map_width)
		{
			validate_map(game, ft_atoi(parsing[x]), a, x);
			free(parsing[x]);
			x++;
		}
		free(parsing);
		free(line);
		a++;
	}
	close(fd);
	init(game);
}

/*
** Main init to start the game.
*/

void	init(t_game *game)
{
	game->pos_x = (int)game->map_height / 2 + 0.5;
	game->pos_y = (int)game->map_width / 2 + 0.5;
	game->dir_x = -1;
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0.66;
	game->img = NULL;
	game->sprite = (t_sprite*)malloc(sizeof(t_sprite));
	game->sprite->x = 27.9;
	game->sprite->y = 8.0;
	game->sprite->texture = 5;
	game->status = 0;
	game->accel_on = 0;
	game->update_t = UINT_MAX;
	game->pointer = 1;
	game->menu = 1;
}

void	floory(t_game *game, t_point *p, double wall_x)
{
	if (game->side == 0 && game->ray_dirx > 0)
	{
		p->floor_x = game->map_x;
		p->floor_y = game->map_y + wall_x;
	}
	else if (game->side == 0 && game->ray_dirx < 0)
	{
		p->floor_x = game->map_x + 1.0;
		p->floor_y = game->map_y + wall_x;
	}
	else if (game->side == 1 && game->ray_diry > 0)
	{
		p->floor_x = game->map_x + wall_x;
		p->floor_y = game->map_y;
	}
	else
	{
		p->floor_x = game->map_x + wall_x;
		p->floor_y = game->map_y + 1.0;
	}
}
