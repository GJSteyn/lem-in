/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_connect_to_end.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 12:30:28 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/25 12:36:39 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			rooms_connect_to_end(t_list *rooms)
{
	t_room		*room;

	while (rooms)
	{
		room = (t_room*)rooms->content;
		if (room->heuristic == 0 && room->type != end)
		{
			ft_putstr_fd("Room '", 2);
			ft_putstr_fd(room->name, 2);
			ft_putstr_fd("' does not connect to the end\n", 2);
			return (0);
		}
	}
	return (1);
}