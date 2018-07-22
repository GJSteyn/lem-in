/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.wethinkcode.co.z    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:16:32 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/22 13:17:57 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <string.h>

typedef enum		e_rmflag { start, end, normal } t_rmflag;

typedef struct		s_vect2
{
	int				x;
	int				y;
}					t_vect2;

typedef struct		s_room
{
	size_t			idx;
	char			*name;
	struct s_room	**conx;
	t_vect2			coords;
	t_rmflag		type;
}					t_room;

typedef struct		s_ant
{
	size_t			num;
	t_room			room;
}					t_ant;

#endif