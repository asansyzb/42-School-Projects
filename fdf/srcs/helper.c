/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:39:31 by asansyzb          #+#    #+#             */
/*   Updated: 2019/02/13 02:09:14 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			find_min_max(int n, int *min, int *max)
{
	if (n > *max)
		*max = n;
	if (n < *min)
		*min = n;
}

void			ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void			ft_swap_points(t_point **p)
{
	ft_swap(&((*p)->x1), &((*p)->x2));
	ft_swap(&((*p)->y1), &((*p)->y2));
	ft_swap(&((*p)->z1), &((*p)->z2));
}

int				ft_abs(int a)
{
	if (a >= 0)
		return (a);
	return (-a);
}

void			malloc_lines(t_vect **t)
{
	if ((*t)->line_x == NULL)
		(*t)->line_x = (int*)ft_memalloc(sizeof(int) * (*t)->w);
	if ((*t)->line_y == NULL)
		(*t)->line_y = (int*)ft_memalloc(sizeof(int) * (*t)->w);
}
