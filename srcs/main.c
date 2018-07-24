/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:15:06 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/24 10:24:06 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

void        putlist(t_list *conx)
{
    while (conx)
    {
        t_room *inside = (t_room*)conx->content;
        ft_putstr_fd(inside->name, 2);
        conx = conx->next;
        ft_putchar_fd('\n', 2);
    }
}

void        roomcnx(t_room *room)
{
    t_list      *conx = room->conx;
    ft_putstr_fd(room->name, 2);
    ft_putendl_fd(":", 2);
    putlist(conx);
}

int         main(void)
{
    t_list      *input;
    t_list      *rooms;
    t_list      *ants;

    input = get_input();
    rooms = init_rooms(input);
    get_links(rooms, input);
    ants = init_ants(input, rooms);
    while (rooms)
    {
        t_room  *room = (t_room*)rooms->content;
        roomcnx(room);
        rooms = rooms->next;
    }
    return (0);
}