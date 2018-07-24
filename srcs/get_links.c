/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 05:47:26 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/24 06:54:36 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_room   *get_room(char *name, t_list *rooms)
{
    while (rooms)
    {
        if (ft_strcmp(name, (char*)((t_room*)rooms->content)->name) == 0)
            return ((t_room*)rooms->content);
        rooms = rooms->next;
    }
    ft_error("Did not find the room :( (get_links.c)");
    return (NULL);
}

static void     add_conx(t_room *room, t_room *conx)
{
    t_list          *new;

    new = ft_lstnew(conx, sizeof(t_room*));
    ft_lstappend(&room->conx, new);
}

void            get_links(t_list *rooms, t_list *in)
{
    t_room      *tmp;
    t_room      *tmp2;
    char        **split;

    while (!is_link((char*)in->content))
        in = in->next;
    if (!in)
        ft_error("Where are the links? (get_links.c)");
    while (in)
    {
        if (is_comment((char*)in->content))
            ;
        else if (is_link((char*)in->content))
        {
            split = ft_strsplit((char*)in->content, '-');
            tmp = get_room(split[0], rooms);
            tmp2 = get_room(split[1], rooms);
            add_conx(tmp, tmp2);
            ft_strldel(&split);
        }
        else
        {
            ft_putstr_fd("Found unexpected line after getting links (get_links.c)", 2);
            break ;
        }
        in = in->next;
    }
}