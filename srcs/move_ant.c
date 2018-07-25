/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 07:41:31 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/25 07:45:07 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		move_ant(t_ant *ant, t_room *room)
{
	ant->room->occupied = 0;
	ant->room = room;
	ant->room->occupied = 1;
	ft_putchar_fd('L', 2);
	ft_putnbr_fd((int)ant->num, 2);
	ft_putchar_fd('-', 2);
	ft_putstr_fd(room->name, 2);
}