/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 22:26:36 by asansyzb          #+#    #+#             */
/*   Updated: 2019/02/13 02:09:53 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	die(t_wind *w)
{
	ft_memdel((void**)&w->m_p);
	ft_memdel((void**)&w->w_p);
	ft_memdel((void**)&w);
	exit(0);
}

int			hook_keydown(int key, t_wind *w)
{
	if (key == 53)
		die(w);
	else if (key == 47 || key == 43)
		change_landschaft(key, w);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		rotate(key, w);
	else if (key == 69 || key == 78)
		zoom(key, w);
	else if (key == 13 || key == 1 || key == 0 || key == 2)
		move(key, w);
	return (0);
}
