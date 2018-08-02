/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 07:10:11 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/02 07:14:44 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_ant(int ant, t_list *ants)
{
	while (ants)
	{
		if ((int)((t_ant*)ants->content)->num == ant)
			return ;
		ants = ants->next;
	}
	ft_putstr_fd("A new ant has appeared! nr: ", 2);
	ft_putnbr_fd(ant, 2);
	ft_error("");
}

void		check_room(int ant, char *room, t_list *rooms)
{
	while (rooms)
	{
		if (ft_strcmp(room, (char*)((t_room*)rooms->content)->name) == 0)
			return ;
		rooms = rooms->next;
	}
	ft_putstr_fd("Ant ", 2);
	ft_putnbr_fd(ant, 2);
	ft_putstr_fd(" tried to make a new room!", 2);
	ft_error("");
}

void		check_connection(int ant, char *room, t_list *ants)
{
	t_list		*cnx;
	t_room		*rm;
	t_ant		*a;

	while ((int)((t_ant*)ants->content)->num != ant)
		ants = ants->next;
	a = (t_ant*)ants->content;
	cnx = (t_list*)a->room->conx;
	while (cnx)
	{
		rm = *(t_room**)cnx->content;
		if (ft_strcmp((char*)rm->name, room) == 0)
			return ;
		cnx = cnx->next;
	}
	ft_putstr_fd("Ant ", 2);
	ft_putnbr_fd(ant, 2);
	ft_putstr_fd(" tried to dig a new tunnel to room ", 2);
	ft_putstr_fd(room, 2);
	ft_error("!");
}

int		valid_move(int ant, char *room, t_list *ants, t_list *rooms)
{
	check_ant(ant, ants);
	check_room(ant, room, rooms);
	check_connection(ant, room, ants);
	move_ant(get_ant(ant, ants), get_room(room, rooms), 1);
	return (1);
}