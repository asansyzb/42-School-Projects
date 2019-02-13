/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <asansyzb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 17:28:59 by asansyzb          #+#    #+#             */
/*   Updated: 2018/11/12 08:02:10 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

static void	free_lst(t_list *list)
{
	t_etr	*t;
	t_list	*next;

	while (list)
	{
		t = (t_etr *)list->content;
		next = list->next;
		ft_memdel((void**)&t);
		ft_memdel((void **)&list);
		list = next;
	}
}

void		err_handler(char *buff, char *line)
{
	ft_memdel((void**)&buff);
	ft_memdel((void**)&line);
	ft_putstr("error\n");
	exit(1);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		tetr_count;
	t_list	*list;
	t_map	*map;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	list = NULL;
	tetr_count = 0;
	if ((list = reader(fd, &tetr_count, list)) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	map = create_map(solve(list, tetr_count));
	place_map(list, map);
	print_map(map);
	clean_map(map);
	free_lst(list);
	close(fd);
	return (0);
}
