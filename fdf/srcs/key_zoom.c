/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 23:16:29 by asansyzb          #+#    #+#             */
/*   Updated: 2019/02/13 02:09:22 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	zoom_in(t_wind *w)
{
	w->z += 10;
	mlx_clear_window(w->m_p, w->w_p);
	get_points(w);
	draw(w);
}

static void	zoom_out(t_wind *w)
{
	w->z -= (w->z > -10) ? 10 : 0;
	mlx_clear_window(w->m_p, w->w_p);
	get_points(w);
	draw(w);
}

void		zoom(int key, t_wind *w)
{
	if (key == 69)
		zoom_in(w);
	else if (key == 78)
		zoom_out(w);
}
