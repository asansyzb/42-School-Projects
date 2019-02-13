/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:42:24 by asansyzb          #+#    #+#             */
/*   Updated: 2019/02/13 02:08:47 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_wind			*init_window(void)
{
	t_wind	*w;

	if (!(w = (t_wind*)ft_memalloc(sizeof(t_wind))))
	{
		ft_putstr("could init minilibx\n");
		exit(1);
	}
	w->min = 2147483647;
	w->max = -2147483648;
	w->coef = 1;
	w->h = HEIGHT;
	w->w = WIDTH;
	w->a_x = 0;
	w->a_y = 0;
	w->cnt = 0;
	w->z = 0;
	w->p_x = WIDTH / 2;
	w->p_y = HEIGHT / 2;
	w->lst = NULL;
	w->m_p = mlx_init();
	w->w_p = mlx_new_window(w->m_p, w->w, w->h, "Fdf");
	return (w);
}

int				main(int argc, char **argv)
{
	t_wind	*w;
	int		fd;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf input_file\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	w = init_window();
	if ((w->lst = reader(fd, &(w->cnt))) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	get_points(w);
	draw(w);
	mlx_key_hook(w->w_p, hook_keydown, w);
	mlx_loop(w->m_p);
	free_lst(&(w->lst));
	close(fd);
}
