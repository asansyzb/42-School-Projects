/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <asansyzb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 17:32:15 by asansyzb          #+#    #+#             */
/*   Updated: 2018/11/12 08:38:06 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_point	*new_point(int x, int y)
{
	t_point *p;

	p = ft_memalloc(sizeof(t_point));
	p->x = x;
	p->y = y;
	return (p);
}

static void		tetri_shape(char *str, t_point *min, t_point *max)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			min->y = ft_min(i / 5, min->y);
			max->y = ft_max(i / 5, max->y);
			min->x = ft_min(i % 5, min->x);
			max->x = ft_max(i % 5, max->x);
		}
		i++;
	}
}

static t_etr	*make_tetri(char *tmp, char letter)
{
	t_etr	*t;
	int		i;
	int		j;
	t_point	*mi;
	t_point	*ma;

	mi = new_point(5, 5);
	ma = new_point(-1, -1);
	tetri_shape(tmp, mi, ma);
	t = ft_memalloc(sizeof(t_etr));
	t->w = ma->x - mi->x + 1;
	t->h = ma->y - mi->y + 1;
	t->l = letter;
	i = -1;
	while (++i < t->h)
	{
		j = -1;
		while (++j < t->w)
			if (*(tmp + (mi->x + j) + (i + mi->y) * 5) == '#')
				*((t->s) + i) |= (1 << (16 - j - 1));
	}
	ft_memdel((void **)&mi);
	ft_memdel((void **)&ma);
	return (t);
}

static int		validate(char *tmp)
{
	int	i;
	int	cnt;
	int	hash_cnt;

	i = -1;
	hash_cnt = 0;
	cnt = 0;
	while (++i < 20)
	{
		if (tmp[i] != '#' && tmp[i] != '.' && tmp[i] != '\n')
			return (0);
		if (tmp[i] == '#')
		{
			((i + 1) < 20 && tmp[i + 1] == '#') ? cnt++ : cnt;
			((i - 1) >= 0 && tmp[i - 1] == '#') ? cnt++ : cnt;
			((i + 5) < 20 && tmp[i + 5] == '#') ? cnt++ : cnt;
			((i - 5) >= 0 && tmp[i - 5] == '#') ? cnt++ : cnt;
			hash_cnt++;
		}
	}
	return ((cnt == 6 || cnt == 8) && hash_cnt == 4);
}

t_list			*reader(int fd, int *tetr_count, t_list *list)
{
	int		cnt;
	char	*line;
	char	*b;
	char	l;

	b = ft_strnew(1);
	cnt = 0;
	l = 'A';
	while (get_next_line(fd, &line) == 1)
	{
		if ((cnt != 4 && ft_strlen(line) != 4) || (cnt == 4 && ft_strlen(line)))
			err_handler(b, line);
		b = (ft_strlen(line) == 4) ? ft_strupd(b, ft_strjoin(line, "\n")) : b;
		if (cnt == 3)
		{
			(!validate(b)) ? err_handler(b, line) : (*tetr_count)++;
			ft_lstaddtail(&list, ft_lstnew(make_tetri(b, l++), sizeof(t_etr)));
			ft_bzero(b, ft_strlen(b));
		}
		cnt++;
		cnt %= 5;
		ft_memdel((void**)&line);
	}
	ft_memdel((void**)&b);
	return ((cnt != 4) ? NULL : list);
}
