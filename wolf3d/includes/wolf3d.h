/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:02:56 by vmuradia          #+#    #+#             */
/*   Updated: 2019/01/03 20:51:58 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <time.h>
# include <fcntl.h>
# include <stdio.h>

# define SCR_WIDTH 1024
# define SCR_HEIGHT 1024
# define NUM_SPRITE 1
# define DIV 1

typedef struct	s_point
{
	double		floor_x;
	double		floor_y;
	double		dist_wall;
	double		dist_play;
	double		c_dist;
	double		fl_x;
	double		fl_y;
	double		weight;
	int			floortex_y;
	int			floortex_x;
	int			col;
}				t_point;

typedef struct	s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
	int			width;
	int			height;
}				t_image;

typedef	struct	s_sprite
{
	double		x;
	double		y;
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		t_x;
	double		t_y;
	double		v_move;
	int			v_move_down;
	int			texture;
	int			i;
	int			sprite_screen_x;
	int			sprite_h;
	int			sprite_w;
	int			start_y;
	int			end_y;
	int			start_x;
	int			end_x;
	int			tex_x;
	int			d;
	int			tex_y;
	int			color;
	int			tex_w;
	int			tex_h;
}				t_sprite;

typedef struct	s_game
{
	void		*m_p;
	void		*w_p;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		ray_dirx;
	double		ray_diry;
	int			map_x;
	int			map_y;
	double		sidedistx;
	double		sidedisty;
	double		deldistx;
	double		deldisty;
	double		pwalld;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			map_width;
	int			map_height;
	int			**map;
	int			line_h;
	int			draw_st;
	int			draw_end;
	double		frame_time;
	double		movespeed;
	double		rot_speed;
	int			status;
	double		buffer[SCR_WIDTH];
	t_sprite	*sprite;
	t_image		*texture[7];
	t_image		*img;
	clock_t		start_t;
	clock_t		end_t;
	time_t		update_t;
	time_t		accel_t;
	time_t		accel_cd_t;
	int			accel_on;
	int			menu;
	int			pointer;
	int			color;
	int			start_x;
	int			start_y;
}				t_game;

void			get_info(char *file, t_game *game, int fd, char *line);
int				keys(int key, t_game *game);
void			wolf(t_game *game);
void			init(t_game *game);
void			read_map(char *file, t_game *game, int fd, char *line);
void			lean_right(t_game *game);
void			lean_left(t_game *game);
void			go_back(t_game *game);
void			move_forward(t_game *game);
t_image			*del_image(void *m_p, t_image *img);
void			image_set_pixel(t_image *image, int x, int y, int col);
t_image			*new_image(t_game *w);
t_image			*xpm_to_image(char *f, void *m_p);
int				load_textures(t_game *game);
void			floory(t_game *game, t_point *p, double wall_x);
void			sky(t_game *game, double wall_x, int x);
void			dda(t_game *game, int *n);
void			calc_wall(t_game *game, double *wall_x);
void			draw_wall(t_game *game, int *n, double wall_x, int x);
void			calc_textures(t_game *game, int y, int x, t_point *p);
void			draw(t_game *game);
void			show_menu(t_game *game);
void			draw_minimap(t_game *g);
void			draw_sprite(t_game *g, t_sprite *s);
void			die(char *s);

#endif
