/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:05:06 by vmuradia          #+#    #+#             */
/*   Updated: 2019/02/13 03:08:53 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			func_close(t_game *g)
{
	(void)g;
	exit(0);
	return (0);
}

static int	loop_hook(t_game *g)
{
	char	*tmp;

	if (!g->menu && (time(NULL) - g->update_t >= 1 || g->status))
	{
		if (g->img)
			del_image(g->m_p, g->img);
		g->img = new_image(g);
		wolf(g);
		mlx_put_image_to_window(g->m_p, g->w_p, g->img->image, 0, 0);
		tmp = ft_itoa((int)(g->frame_time));
		mlx_string_put(g->m_p, g->w_p, SCR_WIDTH - 100, 50,
			0xffff00, tmp);
		if (!g->status)
			g->update_t++;
		free(tmp);
	}
	g->status = 0;
	return (1);
}

void		show_menu(t_game *g)
{
	int	x;
	int	y;
	int	i;

	x = SCR_WIDTH / 2;
	y = SCR_HEIGHT / 2;
	i = -1;
	mlx_string_put(g->m_p, g->w_p, x, y, 0x00ff00, "Play game");
	mlx_string_put(g->m_p, g->w_p, x, y + 100, 0xff0000, "Quit");
	while (++i < 100)
		mlx_pixel_put(g->m_p, g->w_p, x + i, y +
			(g->pointer ? 0 : 100) + 30, 0xffff00);
}

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_game	*game;

	fd = 0;
	line = NULL;
	if (argc == 2)
	{
		game = (t_game*)malloc(sizeof(t_game));
		read_map(argv[1], game, fd, line);
		game->m_p = mlx_init();
		game->w_p = mlx_new_window(game->m_p, SCR_WIDTH, SCR_HEIGHT,
			"Game");
		load_textures(game);
		show_menu(game);
		mlx_hook(game->w_p, 2, 5, keys, game);
		mlx_hook(game->w_p, 17, 0, func_close, game);
		mlx_loop_hook(game->m_p, loop_hook, game);
		mlx_loop(game->m_p);
	}
	else if (argc < 2)
		ft_putendl("Please enter the name of the map");
	else
		return (-1);
}
