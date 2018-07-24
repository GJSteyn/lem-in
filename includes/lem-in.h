/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:16:32 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/24 05:58:20 by gsteyn           ###   ########.fr       */
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
	int				occupied;
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
int					is_room(char *str);
int					is_link(char *str);

int					valid_input(t_list *input);

t_list				*get_map(void);

t_list              *init_rooms(t_list *input);

t_list				*init_ants(t_list *input, t_list *rooms);

void	            get_links(t_list *rooms, t_list *input);

#endif