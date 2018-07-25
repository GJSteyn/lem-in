/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:15:06 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/25 08:06:52 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
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
	rooms = init_rooms(input);
	get_links(rooms, input);
	ants = init_ants(input, rooms);
	num_ants = ft_lstlen(ants);
	get_heuristic(rooms);
	// while (rooms)
	// {
	// 	ft_putstr_fd(((t_room*)rooms->content)->name, 2);
	// 	ft_putendl_fd(":", 2);
	// 	ft_putnbr_fd(((t_room*)rooms->content)->heuristic, 2);
	// 	ft_putchar_fd('\n', 2);
	// 	rooms = rooms->next;
	// }
	finished_ants = 0;
	while (finished_ants != num_ants)
	{
		find_path(ants);
		finished_ants = count_finished_ants(ants);
		if (finished_ants != num_ants)
			ft_putchar_fd('\n', 2);
	}
	return (0);
}
