/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heuristic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.wethinkcode.co.z    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:34:20 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/24 17:48:48 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_room       *get_end(t_list *rooms)
{
    t_room      *room;
    while (rooms)
    {
        room = (t_room*)rooms->content;
        if (room->type == end)
            return (room);
        rooms = rooms->next;
    }
}

static void         dist_from_end(t_list *rooms)
{
    t_room  *end;
    t_list  *conx;
    t_room  *conroom;
    int     dist;

    dist = 0;
    end = get_end(rooms);
    conx = end->conx;
    end->heuristic = dist;
    while (conx)
    {
        conroom = (t_room*)conx->content;
    }
}

void                get_heuristic(t_list *rooms)
{
    dist_from_end(rooms);
}