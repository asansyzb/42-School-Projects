/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:06:11 by vmuradia          #+#    #+#             */
/*   Updated: 2019/01/03 21:13:54 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_image		*del_image(void *m_p, t_image *img)
{
	if (img != NULL)
	{
		if (img->image != NULL)
			mlx_destroy_image(m_p, img->image);
		free(img);
	}
	return (NULL);
}

void		image_set_pixel(t_image *image, int x, int y, int color)
{
	if (x < SCR_WIDTH && x > 0 && y < SCR_HEIGHT && y > 0)
		*(int*)(image->ptr + ((x + (y << 10)) << 2)) = color;
}

t_image		*new_image(t_game *w)
{
	t_image *img;

	if (!(img = (t_image*)malloc(sizeof(t_image))))
		return (NULL);
	if (!(img->image = mlx_new_image(w->m_p, SCR_WIDTH, SCR_HEIGHT)))
		return (del_image(w, img));
	img->ptr = mlx_get_data_addr(img->image, &img->bpp,
				&img->stride, &img->endian);
	return (img);
}

t_image		*xpm_to_image(char *f, void *m_p)
{
	t_image	*img;

	if (!(img = (t_image*)malloc(sizeof(t_image))))
		return (NULL);
	if (!(img->image = mlx_xpm_file_to_image(m_p, f, &img->width,
		&img->height)))
		return (del_image(m_p, img));
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->stride,
		&img->endian);
	return (img);
}

int			load_textures(t_game *game)
{
	char		*path[7];
	t_image		*img;
	int			i;

	path[0] = "pics/greenfloor.xpm";
	path[1] = "pics/wood.xpm";
	path[2] = "pics/metal.xpm";
	path[3] = "pics/brick.xpm";
	path[4] = "pics/stone.xpm";
	path[5] = "pics/enot.xpm";
	path[6] = "pics/sky_lf.xpm";
	i = -1;
	while (++i < 7)
	{
		if (!(img = xpm_to_image(path[i], game->m_p)))
			return (1);
		game->texture[i] = img;
	}
	return (0);
}
