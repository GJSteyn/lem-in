/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:41:25 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/25 06:42:24 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

static t_ant		*new_ant(size_t num, t_room *room)
{
	t_ant	*ret;

	ret = (t_ant *)ft_memalloc(sizeof(t_ant));
	ret->num = num;
	ret->room = room;
	return (ret);
}

static void			add_ant(t_list **dst, size_t num, t_room *room)
{
	t_list	*tmp;

	tmp = ft_lstnew(new_ant(num, room), sizeof(t_ant));
	ft_lstappend(dst, tmp);
}

static t_room		*get_start(t_list *rooms)
{
	while (rooms)
	{
		if (((t_room*)rooms->content)->type == start)
			return ((t_room*)rooms->content);
		rooms = rooms->next;
	}
	ft_error("Start room not found - init_ants.c");
	return (NULL);
}

t_list				*init_ants(t_list *in, t_list *rooms)
{
	size_t		idx;
	int			num_ants;
	t_list		*ret;
	t_room		*start;

	idx = 0;
	start = get_start(rooms);
	ret = NULL;
	while (is_comment((char*)in->content))
		in = in->next;
	if (!ft_is_num((char*)in->content))
		ft_error("Was expecting num of ants.\n(init_ants.c)");
	else
	{
		num_ants = ft_atoi((char*)in->content);
		if (num_ants == 0)
			ft_error("No ants? What's the point?");
		start->occupied = 1;
		while (idx < (size_t)num_ants)
			add_ant(&ret, idx++, start);
	}
	return (ret);
}
