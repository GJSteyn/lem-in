/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 05:49:53 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/01 10:52:59 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		check_ant(int ant, t_list *ants)
{
	while (ants)
	{
		if ((int)((t_ant*)ants->content)->num == ant)
			return ;
		ants = ants->next;
	}
	ft_putstr_fd("A new ant has appeared! nr: ", 2);
	ft_putnbr_fd(ant, 2);
	ft_error("");
}

static void		check_room(int ant, char *room, t_list *rooms)
{
	while (rooms)
	{
		if (ft_strcmp(room, (char*)((t_room*)rooms->content)->name) == 0)
			return ;
		rooms = rooms->next;
	}
	ft_putstr_fd("Ant ", 2);
	ft_putnbr_fd(ant, 2);
	ft_putstr_fd(" tried to make a new room!", 2);
	ft_error("");
}

static void		check_connection(int ant, char *room, t_list *ants)
{
	t_list		*cnx;
	t_room		*rm;
	t_ant		*a;

	while ((int)((t_ant*)ants->content)->num != ant)
		ants = ants->next;
	a = (t_ant*)ants->content;
	cnx = (t_list*)a->room->conx;
	while (cnx)
	{
		rm = *(t_room**)cnx->content;
		if (ft_strcmp((char*)rm->name, room) == 0)
			return ;
		cnx = cnx->next;
	}
	ft_putstr_fd("Ant ", 2);
	ft_putnbr_fd(ant, 2);
	ft_putstr_fd(" tried to dig a new tunnel to room ", 2);
	ft_putstr_fd(room, 2);
	ft_error("!");
}

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

static int		valid_move(int ant, char *room, t_list *ants, t_list *rooms)
{
	check_ant(ant, ants);
	check_room(ant, room, rooms);
	check_connection(ant, room, ants);
	move_ant(get_ant(ant, ants), get_room(room, rooms), 1);
	return (1);
}

static void		run_instructions(t_list *instr, t_list *rooms, t_list *ants)
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
