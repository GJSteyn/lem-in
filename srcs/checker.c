/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 05:49:53 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/02 07:23:04 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant			*get_ant(int ant, t_list *ants)
{
	while (((t_ant*)ants->content)->num != (size_t)ant)
		ants = ants->next;
	return ((t_ant*)ants->content);
}

t_room			*get_room(char *room, t_list *rooms)
{
	while (ft_strcmp(((t_room*)rooms->content)->name, room) != 0)
		rooms = rooms->next;
	return ((t_room*)rooms->content);
}

void		run_instructions(t_list *instr, t_list *rooms, t_list *ants)
{
	char	**split;
	char	*room;
	int		ant;
	int		i;

	i = 0;
	while (instr)
	{
		if (!is_instruction((char*)instr->content))
		{
			ft_putstr_fd("Instruction: ", 2);
			ft_putstr_fd((char*)instr->content, 2);
			ft_error(" is invalid");
		}
		split = ft_strsplit(((char*)instr->content) + 1, '-');
		ant = ft_atoi(split[0]);
		room = split[1];
		if (valid_move(ant, room, ants, rooms))
		{
			ft_strldel(&split);
			instr = instr->next;
		}
	}
}

void			check_ants(t_list *ants)
{
	while (ants)
	{
		if (((t_ant*)ants->content)->room->type != end)
		{
			ft_putstr_fd("Ant ", 2);
			ft_putnbr_fd(((t_ant*)ants->content)->num, 2);
			ft_error(" has sadly been left behind");
		}
		ants = ants->next;
	}
}

int				main(void)
{
	t_list			*input;
	t_list			*rooms;
	t_list			*ants;
	t_list			*instr;

	input = get_input();
	rooms = init_rooms(input);
	get_links(rooms, input);
	ants = init_ants(input, rooms);
	instr = get_instructions(input);
	run_instructions(instr, rooms, ants);
	check_ants(ants);
	ft_putstr_fd("All ants have successfully navigated to the end!\n", 2);
	return (0);
}
