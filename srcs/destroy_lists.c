/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_lists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 17:47:39 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/28 13:43:53 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		destroy_room(t_room **room)
{
	void		*name;
	t_list		*conx;

	name = (*room)->name;
	conx = (*room)->conx;
	ft_memdel(&name);
	ft_lstdel(&conx, &ft_lstdelcontent);
	ft_memdel((void**)room);
}

void			destroy_rooms(t_list **rooms)
{
	t_list		*tmp;
	t_room		*room;

	tmp = (*rooms)->next;
	while (*rooms)
	{
		room = (t_room*)(*rooms)->content;
		destroy_room(&room);
		ft_memdel((void**)(rooms));
		*rooms = tmp;
		if (tmp)
			tmp = tmp->next;
	}
	rooms = NULL;
}

void			destroy_ants(t_list **ants)
{
	t_list		*tmp;
	t_ant		*ant;

	tmp = (*ants)->next;
	while (*ants)
	{
		ant = (t_ant*)(*ants)->content;
		ft_memdel((void**)(&ant));
		ft_memdel((void**)ants);
		*ants = tmp;
		if (tmp)
			tmp = tmp->next;
	}
	ants = NULL;
}

void			destroy_input(t_list **input)
{
	t_list		*tmp;
	char		*str;

	tmp = (*input)->next;
	while (*input)
	{
		str = (*input)->content;
		ft_memdel((void**)(&str));
		ft_memdel((void**)input);
		*input = tmp;
		if (tmp)
			tmp = tmp->next;
	}
	input = NULL;
}

void			destroy_lists(t_list **rooms, t_list **ants, t_list **input)
{
	if (*rooms)
		destroy_rooms(rooms);
	if (*ants)
		destroy_ants(ants);
	if (*input)
		destroy_input(input);
}
