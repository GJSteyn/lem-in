/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:16:32 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/23 10:29:42 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <string.h>
# include "libft.h"

typedef enum		e_rmflag { start, end, normal } t_rmflag;

typedef struct		s_room
{
	size_t			idx;
	int				open;
	char			*name;
	t_list			*conx;
	t_vect2			coords;
	t_rmflag		type;
}					t_room;

typedef struct		s_ant
{
	size_t			num;
	t_room			*room;
}					t_ant;

int					is_end(char *str);
int 		        is_start(char *str);
int 		        is_comment(char *str);

t_list				*get_map(void);
t_list				*init_ants(t_list *maplines);

#endif