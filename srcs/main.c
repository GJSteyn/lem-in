/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:15:06 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/01 13:04:01 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int			main(void)
{
	t_list		*input;
	t_list		*rooms;
	t_list		*ants;

	rooms = NULL;
	ants = NULL;
	input = get_input();
	if (!valid_input(input))
	{
		destroy_input(&input);
		return (0);
	}
	rooms = init_rooms(input);
	get_links(rooms, input);
	if (!valid_map(rooms))
	{
		destroy_lists(&rooms, NULL, &input);
		return (0);
	}
	ants = init_ants(input, rooms);
	get_heuristic(rooms);
	print_input(input);
	find_path(ants);
	destroy_lists(&rooms, &ants, &input);
	return (0);
}
