/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 23:41:46 by asansyzb          #+#    #+#             */
/*   Updated: 2018/12/11 23:56:07 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

static void	init_window(t_wind *w)
{
	w->min_re = (w->type != 1) ? -2.0 : -2.0;
	w->max_re = (w->type != 1) ? 2.0 : 1.0;
	w->min_im = (w->type != 1) ? -2.0 : -1.2;
	w->max_im = w->min_im + (w->max_re - w->min_re) * HEIGHT / WIDTH;
	w->re_factor = (w->max_re - w->min_re) / (WIDTH - 1);
	w->im_factor = (w->max_im - w->min_im) / (HEIGHT - 1);
	w->max_iter = 200;
	w->zoom = 1.01;
	w->x = 0;
	w->freeze = 0;
	w->zoom_factor = 4;
	w->y = 0;
	w->status = 1;
	w->m_p = mlx_init();
	w->w_p = mlx_new_window(w->m_p, WIDTH, HEIGHT, "fract'ol");
	w->image = NULL;
}

static int	check_fractol(char *s)
{
	if (ft_strcmp("mandelbrot", s) == 0)
		return (1);
	else if (ft_strcmp("julia", s) == 0)
		return (2);
	else if (ft_strcmp("burningship", s) == 0)
		return (3);
	else if (ft_strcmp("mcubic", s) == 0)
		return (4);
	else if (ft_strcmp("jcubic", s) == 0)
		return (5);
	return (0);
}

static void	init_project(int type)
{
	t_wind	*w;

	if (!(w = (t_wind *)malloc(sizeof(t_wind))))
		die("could not init project");
	w->type = type;
	init_window(w);
	if (w->type == 2 || w->type == 5)
		mlx_hook(w->w_p, 6, 0, mouse_move, w);
	mlx_hook(w->w_p, 4, 0, hook_keydown, w);
	mlx_hook(w->w_p, 2, 0, key_hook, w);
	mlx_loop_hook(w->m_p, loop_hook, w);
	mlx_loop(w->m_p);
}

int			main(int argc, char **argv)
{
	int		i;
	int		type;
	pid_t	pd;
	int		status;

	i = 0;
	status = 0;
	if (argc == 1)
		die("usage: ./fractol [mandelbrot, julia, burningship, cubic]\n");
	while (++i < argc)
	{
		if (!(type = check_fractol(argv[i])))
			die("available fractols: mandelbrot, julia, burningship, cubic\n");
		if ((pd = fork()) == 0)
			init_project(type);
	}
	while ((pd = wait(&status)) > 0)
		;
	return (0);
}
