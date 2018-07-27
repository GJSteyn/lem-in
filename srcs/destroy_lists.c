/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_lists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 17:47:39 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/27 18:05:12 by gsteyn           ###   ########.fr       */
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
	//ft_lstdel(&conx);
	ft_memdel((void**)room);
}

void			destroy_rooms(t_list **rooms)
{
	t_list		*tmp;
	t_room		*room;

	tmp = (*rooms)->next;
	while (*rooms)
	{
		ft_putstr_fd("Destroying room\n", 2);
		room = (*rooms)->content;
		destroy_room(&room);
		ft_memdel((void**)(rooms));
		*rooms = tmp;
		tmp = tmp->next;
	}
	rooms = NULL;
}
