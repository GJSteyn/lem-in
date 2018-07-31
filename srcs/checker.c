/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 05:49:53 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/31 12:11:48 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
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
		ft_putstr_fd("Here\n", 2);
		rm = (t_room*)cnx->content;
		ft_putstr_fd("Here\n", 2);
		if (!room)
			ft_putstr_fd("WTF?\n", 2);
		if (!rm)
			ft_putstr_fd("WTF?1\n", 2);
		ft_putstr_fd(rm->name, 2);
		ft_putstr_fd((char*)rm->name, 2);
		if (ft_strcmp((char*)rm->name, room) == 0)
			return ;
		ft_putstr_fd("Doing\n", 2);
		cnx = cnx->next;
	}
	ft_putstr_fd("Ant ", 2);
	ft_putnbr_fd(ant, 2);
	ft_putstr_fd(" tried to dig a new tunnel to room ", 2);
	ft_putstr_fd(room, 2);
	ft_error("!");
}

static int		valid_move(int ant, char *room, t_list *ants, t_list *rooms)
{
	ft_putstr_fd("Checking ant\n", 2);
	check_ant(ant, ants);
	ft_putstr_fd("Checking room\n", 2);
	check_room(ant, room, rooms);
	ft_putstr_fd("Checking connection\n", 2);
	check_connection(ant, room, ants);
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
		ft_putnbr_fd(i++, 2);
		ft_putchar_fd(' ', 2);
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
			ft_putstr_fd("Got\n", 2);
			ft_strldel(&split);
			instr = instr->next;
		}
	}
	ft_putstr_fd("End of instructions\n", 2);
}
*/

int				main(void)
{
	t_list			*input;
	t_list			*rooms;
	t_list			*ants;
	//t_list			*instr;

	input = get_input();
	rooms = init_rooms(input);
	get_links(rooms, input);
	ants = init_ants(input, rooms);
	/*
	t_room			*room;
	t_list			*cnx;
	while (rooms)
	{
		room = (t_room*)rooms->content;
		cnx = room->conx;
		while (cnx)
		{
			room = (t_room*)cnx->content;
			ft_putendl_fd(room->name, 2);
			cnx = cnx->next;
		}
		rooms = rooms->next;
	}
	*/
	//run_instructions(instr, rooms, ants);
	return (0);
}
