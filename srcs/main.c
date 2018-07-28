/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:15:06 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/28 12:33:09 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static int	count_finished_ants(t_list *ants)
{
	int		ret;
	t_ant	*ant;

	ret = 0;
	while (ants)
	{
		ant = (t_ant*)ants->content;
		if (ant->room->type == end)
			ret++;
		ants = ants->next;
	}
	return (ret);
}

int			main(void)
{
	t_list		*input;
	t_list		*rooms;
	t_list		*ants;
	int			num_ants;
	int			finished_ants;

	input = get_input();
	if (!valid_input(input))
		return (0);
	rooms = init_rooms(input);
	get_links(rooms, input);
	if (!valid_map(rooms))
		ft_error("Not a valid map");
	ants = init_ants(input, rooms);
	num_ants = ft_lstlen(ants);
	get_heuristic(rooms);
	finished_ants = 0;
	while (finished_ants != num_ants)
	{
		find_path(ants);
		finished_ants = count_finished_ants(ants);
		if (finished_ants != num_ants)
			ft_putchar_fd('\n', 2);
	}
	destroy_rooms(&rooms);
	destroy_ants(&ants);
	destroy_input(&input);
	return (0);
}
