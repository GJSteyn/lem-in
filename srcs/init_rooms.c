/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:43:59 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/24 09:03:38 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

static t_room   *new_room(size_t idx, char *nm, t_vect2 crd, t_rmflag fl)
{
    t_room *ret;

    ret = (t_room *)ft_memalloc(sizeof(t_room));
    ret->idx = idx;
    ret->occupied = 0;
    ret->heuristic = 0;
    ret->name = ft_strdup(nm);
    ret->conx = NULL;
    ret->coords = crd;
    ret->type = fl;
    return (ret);
}

static void     add_room(t_list **dst, char *rmstr, size_t idx, t_rmflag fl)
{
    char        **split;
    t_vect2     coords;
    t_list      *tmp;

    split = ft_strsplit(rmstr, ' ');
    coords = ft_itovect(ft_atoi(split[1]), ft_atoi(split[2]));
    tmp = ft_lstnew(new_room(idx, split[0], coords, fl), sizeof(t_room));
    ft_lstappend(dst, tmp);
    ft_strldel(&split);
}

t_list          *init_rooms(t_list *in)
{
    size_t      idx;
    t_list      *ret;

    idx = 0;
    ret = NULL;
    while (in && !is_room((char *)in->content) && !is_start((char*)in->content)
        && !is_end((char*)in->content))
        in = in->next;
    while (in)
    {
        if (is_comment((char *)in->content))
            ;
        else if (is_room((char *)in->content))
            add_room(&ret, (char*)in->content, idx++, normal);
        else if (is_start((char*)in->content))
        {
            in = in->next;
            add_room(&ret, (char*)in->content, idx++, start);
        }
        else if (is_end((char*)in->content))
        {
            in = in->next;
            add_room(&ret, (char*)in->content, idx++, end);
        }
        else if (is_link((char*)in->content))
            break ;
        if (in->next)
            in = in->next;
    }
    return (ret);
}