/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 23:35:35 by asansyzb          #+#    #+#             */
/*   Updated: 2019/02/13 02:09:45 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	move_up(t_wind *w)
{
	w->p_y -= 10;
	mlx_clear_window(w->m_p, w->w_p);
	get_points(w);
	draw(w);
}

static void	move_down(t_wind *w)
{
	w->p_y += 10;
	mlx_clear_window(w->m_p, w->w_p);
	get_points(w);
	draw(w);
}

static void	move_left(t_wind *w)
{
	w->p_x -= 10;
	mlx_clear_window(w->m_p, w->w_p);
	get_points(w);
	draw(w);
}

static void	move_right(t_wind *w)
{
	w->p_x += 10;
	mlx_clear_window(w->m_p, w->w_p);
	get_points(w);
	draw(w);
}

void		move(int key, t_wind *w)
{
	if (key == 13)
		move_up(w);
	else if (key == 1)
		move_down(w);
	else if (key == 0)
		move_left(w);
	else if (key == 2)
		move_right(w);
}
