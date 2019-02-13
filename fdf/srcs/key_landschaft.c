/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_landschaft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 22:27:37 by asansyzb          #+#    #+#             */
/*   Updated: 2019/02/13 02:09:07 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	increase_landschaft(t_wind *w)
{
	mlx_clear_window(w->m_p, w->w_p);
	w->coef++;
	get_points(w);
	draw(w);
}

static void	decrease_landschaft(t_wind *w)
{
	w->coef -= (w->coef > 1) ? 1 : 0;
	mlx_clear_window(w->m_p, w->w_p);
	get_points(w);
	draw(w);
}

void		change_landschaft(int key, t_wind *w)
{
	if (key == 47)
		increase_landschaft(w);
	else
		decrease_landschaft(w);
}
