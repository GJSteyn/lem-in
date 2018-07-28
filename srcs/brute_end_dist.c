/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_end_dist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 11:30:38 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/28 13:27:41 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "limits.h"

static t_room	*room_with_smallest_heuristic(t_list *conx)
{
	t_room		*ret;
	t_room		*conroom;
	int			best;

	best = INT_MAX;
	ret = NULL;
	while (conx)
	{
		conroom = *(t_room**)conx->content;
		if (conroom->heuristic < best && !conroom->occupied)
		{
			ret = conroom;
			best = conroom->heuristic;
		}
		conx = conx->next;
	}
	return (ret);
}

void			brute_end_dist(t_ant *ant)
{
	t_room		*best;

	if (ant->room->type != end)
	{
		best = room_with_smallest_heuristic(ant->room->conx);
		if (!best)
			return ;
		if (best->heuristic < ant->room->heuristic)
		{
			move_ant(ant, best);
			ft_putchar_fd(' ', 2);
		}
	}
}
