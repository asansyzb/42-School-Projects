/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:41:27 by vmuradia          #+#    #+#             */
/*   Updated: 2018/11/09 14:17:50 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clean_map(t_map *map)
{
	int i;

	i = -1;
	while (++i < map->size)
		ft_memdel((void **)&(map->map[i]));
	ft_memdel((void **)&(map->map));
	ft_memdel((void **)&map);
}

t_map	*create_map(int size)
{
	int		i;
	int		j;
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	map->map = (char**)ft_memalloc(sizeof(char*) * size);
	i = -1;
	while (++i < size)
	{
		map->map[i] = ft_strnew(size);
		j = -1;
		while (++j < size)
			map->map[i][j] = '.';
	}
	map->size = size;
	return (map);
}

void	print_map(t_map *map)
{
	int	size;
	int i;

	size = map->size;
	i = -1;
	while (++i < map->size)
	{
		ft_putstr(map->map[i]);
		ft_putchar('\n');
	}
}
