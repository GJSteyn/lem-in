/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 13:01:03 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/26 15:55:20 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		has_start(t_list *rooms)
{
	int			count;
	t_room		*room;

	count = 0;
	while (rooms)
	{
		room = (t_room*)rooms->content;
		if (room->type == start)
			count++;
		rooms = rooms->next;
	}
	if (count > 1)
		ft_error("There is more than one start");
	if (count == 0)
		return (0);
	return (1);
}

static int		has_end(t_list *rooms)
{
	int			count;
	t_room		*room;

	count = 0;
	while (rooms)
	{
		room = (t_room*)rooms->content;
		if (room->type == end)
			count++;
		rooms = rooms->next;
	}
	if (count > 1)
		ft_error("There is more than one end");
	if (count == 0)
		return (0);
	return (1);
}

static t_room	*get_start(t_list *rooms)
{
	while (rooms)
	{
		if (((t_room*)rooms->content)->type == start)
			return ((t_room*)rooms->content);
		rooms = rooms->next;
	}
	return (NULL);
}

static int		end_not_connected(t_list *rooms)
{
	t_room		*start;

	start = get_start(rooms);
	if (start->heuristic == 0)
		return (0);
	return (1);
}

int				valid_map(t_list *rooms)
{
	if (!has_start(rooms))
	{
		ft_putstr_fd("There is no start\n", 2);
		return (0);
	}
	if (!has_end(rooms))
	{
		ft_putstr_fd("There is no end\n", 2);
		return (0);
	}
	if (end_not_connected(rooms))
	{
		ft_putstr_fd("The end is not connected to the start\n", 2);
		return (0);
	}
	return (1);
}
