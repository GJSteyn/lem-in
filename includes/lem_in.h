/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:16:32 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/26 12:27:28 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <string.h>
# include "libft.h"

typedef enum		e_rmflag
{
	start,
	end,
	normal
}					t_rmflag;

typedef struct		s_room
{
	size_t			idx;
	int				occupied;
	int				heuristic;
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
int					is_start(char *str);
int					is_comment(char *str);
int					is_room(char *str);
int					is_link(char *str);
int					is_command(char *str);

int					valid_input(t_list *input);

t_list				*get_input(void);

t_list				*init_rooms(t_list *input);

t_list				*init_ants(t_list *input, t_list *rooms);

void				get_links(t_list *rooms, t_list *input);

void				find_path(t_list *ants);

void				brute_end_dist(t_ant *ant);

void				get_heuristic(t_list *rooms);

void				move_ant(t_ant *ant, t_room *room);

int					rooms_connect_to_end(t_list *rooms);

#endif
