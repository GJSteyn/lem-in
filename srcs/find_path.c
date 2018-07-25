/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 11:29:21 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/25 12:46:24 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		find_path(t_list *ants)
{
	t_ant	*ant;

	while (ants)
	{
		ant = (t_ant*)ants->content;
		brute_end_dist(ant);
		ants = ants->next;
	}
}
