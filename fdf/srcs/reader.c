/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:16:11 by asansyzb          #+#    #+#             */
/*   Updated: 2019/02/13 02:09:29 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			free_lst(t_list **list)
{
	t_vect	*t;
	t_list	*next;

	while (*list)
	{
		t = (t_vect*)(*list)->content;
		ft_memdel((void**)&(t->line));
		ft_memdel((void*)&(t->line_x));
		ft_memdel((void*)&(t->line_y));
		next = (*list)->next;
		ft_memdel((void**)&t);
		ft_memdel((void**)&list);
		*list = next;
	}
}

static t_vect	*make_vector(char *line, int cnt)
{
	t_vect	*t;

	t = (t_vect*)ft_memalloc(sizeof(t_vect));
	t->line_x = NULL;
	t->line_y = NULL;
	t->line = ft_strsplit_toi(line, ' ');
	t->w = cnt;
	return (t);
}

t_list			*reader(int fd, int *cnt)
{
	int		err;
	char	*line;
	t_list	*lst;

	err = -1;
	lst = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		err = (err == -1) ? words_count(line, ' ') : err;
		ft_lstaddtail(&lst, ft_lstnew(make_vector(line, err), sizeof(t_vect)));
		(*cnt)++;
		if (err != words_count(line, ' '))
			free_lst(&lst);
		ft_memdel((void**)&line);
	}
	return (lst);
}

static void		rotate_coordinates(t_wind *w, t_vect **t, int i)
{
	int	c_x;
	int	c_y;

	c_x = 2 * HEIGHT / 6;
	c_y = 2 * WIDTH / 6;
	(*t)->line_x[i] = (w->x - c_x) * cos(w->a_x) - (w->y - c_y) * sin(w->a_x);
	(*t)->line_y[i] = (w->x - c_x) * sin(w->a_x) + (w->y - c_y) * cos(w->a_x);
}

void			get_points(t_wind *w)
{
	t_vect	*t;
	t_list	*tmp;
	int		i;

	tmp = w->lst;
	w->y = 0;
	while (tmp)
	{
		w->y += 2 * HEIGHT / 3 / w->cnt + w->z;
		t = (t_vect*)tmp->content;
		i = -1;
		w->x = 0;
		malloc_lines(&t);
		while (++i < t->w)
		{
			w->x += 2 * WIDTH / 3 / t->w + w->z;
			find_min_max(t->line[i], &(w->min), &(w->max));
			rotate_coordinates(w, &t, i);
			t->line_x[i] = (t->line_x[i] - t->line_y[i]) * cos(w->a_y);
			t->line_y[i] = (t->line_x[i] + t->line_y[i]) * sin(w->a_y)
											- w->coef * (t->line[i]);
		}
		tmp = tmp->next;
	}
}
