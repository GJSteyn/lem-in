/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 07:41:31 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/31 07:45:20 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		move_ant(t_ant *ant, t_room *room)
{
	ant->room->occupied = 0;
	ant->room = room;
	if (room->type != end)
		ant->room->occupied = 1;
	ft_putchar_fd('L', 1);
	ft_putnbr_fd((int)ant->num, 1);
	ft_putchar_fd('-', 1);
	ft_putstr_fd(room->name, 1);
}
