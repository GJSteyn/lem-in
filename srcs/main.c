/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:15:06 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/24 07:17:25 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

int         main(void)
{
    t_list      *input;
    t_list      *rooms;
    t_list      *ants;

    ft_putstr_fd("Getting input\n", 2);
    input = get_input();
    ft_putstr_fd("Getting rooms\n", 2);
    rooms = init_rooms(input);
    ft_putstr_fd("Getting links\n", 2);
    get_links(rooms, input);
    ft_putstr_fd("Getting ants\n", 2);
    ants = init_ants(input, rooms);
    return (0);
}