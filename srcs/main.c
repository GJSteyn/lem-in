/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:15:06 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/26 12:28:11 by gsteyn           ###   ########.fr       */
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

	// ft_putstr_fd("Getting input\n", 2);
	input = get_input();
	if (!valid_input(input))
		return (0);
	// ft_putstr_fd("Getting rooms\n", 2);
	rooms = init_rooms(input);
	// ft_putstr_fd("Getting links\n", 2);
	get_links(rooms, input);
	// ft_putstr_fd("Getting ants\n", 2);
	ants = init_ants(input, rooms);
	num_ants = ft_lstlen(ants);
	// ft_putstr_fd("Getting heuristic\n", 2);
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
