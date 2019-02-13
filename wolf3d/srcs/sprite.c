/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 20:11:31 by vmuradia          #+#    #+#             */
/*   Updated: 2019/01/03 20:11:48 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** t_x stands for transofm_x
*/

void	calc_sprite(t_game *g, t_sprite *s)
{
	s->tex_h = g->texture[s->texture]->height;
	s->tex_w = g->texture[s->texture]->width;
	s->sprite_x = s->x - g->pos_x;
	s->sprite_y = s->y - g->pos_y;
	s->inv_det = 1.0 / (g->plane_x * g->dir_y - g->dir_x * g->plane_y);
	s->t_x = s->inv_det * (g->dir_y * s->sprite_x - g->dir_x * s->sprite_y);
	s->t_y = s->inv_det * (g->plane_x * s->sprite_y - g->plane_y * s->sprite_x);
	s->v_move_down = (int)(g->texture[s->texture]->height / s->t_y);
	s->sprite_screen_x = (int)((SCR_WIDTH >> 1) * (1 + s->t_x / s->t_y));
	s->sprite_h = abs((int)(SCR_HEIGHT / (s->t_y))) / DIV;
	s->start_y = (-s->sprite_h >> 1) + (SCR_HEIGHT >> 1) + s->v_move_down;
	if (s->start_y < 0)
		s->start_y = 0;
	s->end_y = (s->sprite_h >> 1) + (SCR_HEIGHT >> 1) + s->v_move_down;
	if (s->end_y >= SCR_HEIGHT)
		s->end_y = SCR_HEIGHT - 1;
	s->sprite_w = abs((int)(SCR_HEIGHT / (s->t_y))) / DIV;
	s->start_x = (-s->sprite_w >> 1) + s->sprite_screen_x;
	if (s->start_x < 0)
		s->start_x = 0;
	s->end_x = (s->sprite_w >> 1) + s->sprite_screen_x;
	if (s->end_x >= SCR_WIDTH)
		s->end_x = SCR_WIDTH - 1;
}

void	draw_sprite(t_game *g, t_sprite *s)
{
	int		y;
	int		stripe;
	int		n;

	calc_sprite(g, s);
	stripe = s->start_x;
	n = s->texture;
	while (++stripe < s->end_x)
	{
		s->tex_x = (int)(((stripe - ((-s->sprite_w >> 1) +
			s->sprite_screen_x)) << 8) * s->tex_w / s->sprite_w) >> 8;
		y = s->start_y;
		if (s->t_y > 0 && stripe > 0 && stripe < SCR_WIDTH &&
		s->t_y < g->buffer[stripe])
			while (++y < s->end_y)
			{
				s->d = ((y - s->v_move_down) << 8) - (SCR_HEIGHT << 7)
					+ (s->sprite_h << 7);
				s->tex_y = ((s->d * s->tex_h) / s->sprite_h) >> 8;
				s->color = *(int*)&g->texture[n]->ptr[g->texture[n]->stride *
					s->tex_y + s->tex_x * (g->texture[n]->bpp >> 3)];
				if ((s->color & 0x00FFFFFF) != 0)
					image_set_pixel(g->img, stripe, y, s->color);
			}
	}
}
