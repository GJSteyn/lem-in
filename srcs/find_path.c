/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 11:29:21 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/28 13:26:43 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

static void	move_ants(t_list *ants)
{
	t_ant	*ant;

	while (ants)
	{
		ant = (t_ant*)ants->content;
		brute_end_dist(ant);
		ants = ants->next;
	}
}

void		find_path(t_list *ants)
{
	int		finished_ants;
	int		num_ants;

	num_ants = ft_lstlen(ants);
	finished_ants = 0;
	while (finished_ants != num_ants)
	{
		move_ants(ants);
		finished_ants = count_finished_ants(ants);
		ft_putchar_fd('\n', 2);
	}
}
