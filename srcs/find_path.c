/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 11:29:21 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/26 12:28:29 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
