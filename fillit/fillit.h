/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <asansyzb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 17:26:25 by asansyzb          #+#    #+#             */
/*   Updated: 2018/11/12 08:37:48 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdint.h>

typedef struct		s_map {
	int				size;
	char			**map;
}					t_map;

typedef struct		s_etr {
	int				w;
	int				h;
	int				x;
	int				y;
	uint16_t		s[4];
	char			l;
}					t_etr;

typedef struct		s_oint {
	int	x;
	int	y;
}					t_point;

t_list				*reader(int fd, int *tetr_count, t_list *list);
t_map				*create_map(int size);
void				err_handler(char *buff, char *line);
void				print_map(t_map *map);
int					solve(t_list *list, int cnt);
void				clean_map(t_map *map);
void				place_map(t_list *list, t_map *map);

#endif
