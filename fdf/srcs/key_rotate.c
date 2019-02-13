/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 22:26:21 by asansyzb          #+#    #+#             */
/*   Updated: 2019/02/13 02:08:28 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	rotate_left(t_wind *w)
{
	w->a_x += 0.1;
	mlx_clear_window(w->m_p, w->w_p);
	get_points(w);
	draw(w);
}

static void	rotate_right(t_wind *w)
{
	w->a_x -= 0.1;
	mlx_clear_window(w->m_p, w->w_p);
	get_points(w);
	draw(w);
}

static void	rotate_bottom(t_wind *w)
{
	w->a_y -= (w->a_y > 0.1) ? 0.1 : 0;
	mlx_clear_window(w->m_p, w->w_p);
	get_points(w);
	draw(w);
}

static void	rotate_top(t_wind *w)
{
	w->a_y += (w->a_y < 0.9) ? 0.1 : 0;
	mlx_clear_window(w->m_p, w->w_p);
	get_points(w);
	draw(w);
}

void		rotate(int key, t_wind *w)
{
	if (key == 123)
		rotate_left(w);
	else if (key == 124)
		rotate_right(w);
	else if (key == 125)
		rotate_bottom(w);
	else if (key == 126)
		rotate_top(w);
}
