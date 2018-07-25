/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:15:06 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/25 05:40:48 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

int			main(void)
{
	t_list		*input;
	t_list		*rooms;
	t_list		*ants;

	input = get_input();
	rooms = init_rooms(input);
	get_links(rooms, input);
	ants = init_ants(input, rooms);
	find_path(ants);
	return (0);
}
