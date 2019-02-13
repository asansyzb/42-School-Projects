/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <asansyzb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 21:27:47 by asansyzb          #+#    #+#             */
/*   Updated: 2018/11/14 15:41:04 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_piece(uint16_t *map, t_etr *t)
{
	int	i;

	i = -1;
	while (++i < t->h)
		if ((*(map + t->y + i) & (t->s[i] >> t->x)))
			return (0);
	return (1);
}

static void		toggle_piece(uint16_t *map, t_etr *t)
{
	int i;

	i = -1;
	while (++i <= t->h)
		*(map + t->y + i) ^= t->s[i] >> t->x;
}

static int		solve_map(uint16_t *map, int size, t_list *list)
{
	t_etr		*t;

	if (list == NULL)
		return (1);
	t = (t_etr *)(list->content);
	t->y = -1;
	while (++t->y <= size - t->h)
	{
		t->x = -1;
		while (++t->x <= size - t->w)
		{
			if (check_piece(map, t))
			{
				toggle_piece(map, t);
				if (solve_map(map, size, list->next))
					return (1);
				toggle_piece(map, t);
			}
		}
	}
	return (0);
}

void			place_map(t_list *list, t_map *map)
{
	t_etr	*t;
	int		i;
	int		j;

	while (list)
	{
		t = (t_etr *)(list->content);
		i = -1;
		while (++i < t->h)
		{
			j = -1;
			while (++j < t->w)
				if (!!((t->s[i]) & (1 << (16 - j - 1))))
					map->map[t->y + i][t->x + j] = t->l;
		}
		list = list->next;
	}
}

int				solve(t_list *list, int cnt)
{
	uint16_t	map[16];
	int			size;

	size = 2;
	while (size * size < cnt * 4)
		size++;
	ft_bzero(map, sizeof(uint16_t) * 16);
	while (!solve_map(map, size, list) && size < 16)
	{
		ft_bzero(map, sizeof(uint16_t) * 16);
		size++;
	}
	return (size == 17 ? 0 : size);
}
