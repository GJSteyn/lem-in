/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 05:47:26 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/23 11:06:19 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room		*get_room(char *name, t_list *rooms)
{
	while (rooms)
	{
		if (ft_strcmp(name, (char *)((t_room *)rooms->content)->name) == 0)
			return ((t_room *)rooms->content);
		rooms = rooms->next;
	}
	ft_putstr_fd("Did not find the room: ", 2);
	ft_putstr_fd(name, 2);
	ft_error("");
	return (NULL);
}

static void			add_conx(t_list *rooms, char *link)
{
	char	**split;
	t_list	*new;
	t_room	*room1;
	t_room	*room2;

	split = ft_strsplit(link, '-');
	room1 = get_room(split[0], rooms);
	room2 = get_room(split[1], rooms);
	new = ft_lstnew(&room1, sizeof(t_room*));
	ft_lstappend(&room2->conx, new);
	new = ft_lstnew(&room2, sizeof(t_room*));
	ft_lstappend(&room1->conx, new);
	ft_strldel(&split);
}

void				get_links(t_list *rooms, t_list *in)
{
	while (!is_link((char *)in->content))
		in = in->next;
	if (!in)
		ft_error("Where are the links? (get_links.c)");
	while (in)
	{
		if (is_comment((char *)in->content))
			;
		else if (is_command((char*)in->content))
			;
		else if (is_link((char *)in->content))
			add_conx(rooms, (char *)in->content);
		else if (is_link((char*)in->next->content))
		{
			ft_putstr_fd("Bad line in links (get_links.c)\n", 2);
			break ;
		}
		else if (ft_strlen((char*)in->content) == 0)
			break ;
		in = in->next;
	}
}
