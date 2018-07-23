/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:43:59 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/23 15:27:04 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_room       *new_room(size_t index, char *name, t_vect2 coords)
{
    t_room      *ret;

    ret = (t_room*)ft_memalloc(sizeof(t_room));
    ret->idx = index;
    ret->occupied = 0;
    ret->conx = NULL;
    ret->coords = coords;
    ret->type = normal;
    return (ret);
}

t_list              *init_rooms(t_list *maplines)
{
    t_list      *ret;

    while (maplines)
    {
        if (is_comment((char*)maplines->content))
            maplines = maplines->next;
    }
}