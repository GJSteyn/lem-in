/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heuristic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:34:20 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/26 12:28:46 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room		*get_end(t_list *rooms)
{
	t_room		*room;

	while (rooms)
	{
		room = (t_room*)rooms->content;
		if (room->type == end)
			return (room);
		rooms = rooms->next;
	}
	return (NULL);
}

static void			recurse_conx(t_room *room, int dist)
{
	t_list		*tmp;
	t_room		*conroom;

	room->heuristic = dist;
	tmp = room->conx;
	while (tmp)
	{
		conroom = *(t_room**)tmp->content;
		if (conroom->heuristic == 0 && conroom->type != end)
			conroom->heuristic = dist + 1;
		tmp = tmp->next;
		// ft_putstr_fd(conroom->name, 2);
		// ft_putendl_fd(":", 2);
		// ft_putnbr_fd(dist, 2);
		// ft_putchar_fd('\n', 2);
	}
	tmp = room->conx;
	while (tmp)
	{
		conroom = *(t_room**)tmp->content;
		if (conroom->heuristic == dist + 1 && conroom->type != end)
			recurse_conx(conroom, dist + 1);
		tmp = tmp->next;
	}
}

static void			dist_from_end(t_list *rooms)
{
	t_room		*end;
	int			dist;

	dist = 0;
	end = get_end(rooms);
	recurse_conx(end, dist);
}

void				get_heuristic(t_list *rooms)
{
	dist_from_end(rooms);
}
