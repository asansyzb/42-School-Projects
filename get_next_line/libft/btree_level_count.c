/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 23:04:50 by asansyzb          #+#    #+#             */
/*   Updated: 2018/10/24 23:07:31 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		btree_level_count(t_btree *root)
{
	int	cnt;
	int	l;
	int	r;

	cnt = 0;
	l = 0;
	r = 0;
	if (root)
	{
		l = btree_level_count(root->left);
		r = btree_level_count(root->right);
		return (1 + ft_max(l, r));
	}
	return (cnt);
}
