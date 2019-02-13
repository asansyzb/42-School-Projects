/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 23:04:12 by asansyzb          #+#    #+#             */
/*   Updated: 2018/10/24 23:04:29 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	if (root)
	{
		if (!root)
			return (NULL);
		if (root->left)
			return (btree_search_item(root->left, data_ref, cmpf));
		if (cmpf(root->item, data_ref) == 0)
			return (root->item);
		if (root->right)
			return (btree_search_item(root->right, data_ref, cmpf));
	}
	return (NULL);
}
