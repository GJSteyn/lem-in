/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:39:13 by gsteyn            #+#    #+#             */
/*   Updated: 2018/08/02 06:48:48 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		valid_line(char *line)
{
	if (ft_strlen(line) == 0)
		return (0);
	if (line[0] == 'L')
	{
		ft_putstr_fd("Line: ", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd(" starts with an L - that's bad", 2);
		ft_error("");
	}
	if (is_comment(line) || is_room(line) || is_end(line) || is_start(line) ||
		is_link(line) || is_command(line) || ft_is_num(line))
		return (1);
	return (0);
}

static void		check_all_valid(t_list *input)
{
	int		i;

	i = 0;
	while (input)
	{
		if (!valid_line((char*)input->content))
		{
			ft_putstr_fd("Input: '", 2);
			ft_putstr_fd((char*)input->content, 2);
			ft_putstr_fd("' on line: ", 2);
			ft_putnbr_fd(i, 2);
			ft_putendl_fd(" not valid", 2);
			exit(1);
		}
		input = input->next;
		i++;
	}
}

static int		start_and_end_valid(t_list *in)
{
	while (in)
	{
		if (is_start((char*)in->content))
		{
			if (!in->next)
				return (0);
			if (!is_room((char*)in->next->content))
				return (0);
		}
		else if (is_end((char*)in->content))
		{
			if (!in->next)
				return (0);
			if (!is_room((char*)in->next->content))
				return (0);
		}
		in = in->next;
	}
	return (1);
}

int				valid_input(t_list *in)
{
	check_all_valid(in);
	if (!start_and_end_valid(in))
		ft_error("Invalid start or end");
	while (is_comment((char*)in->content))
		in = in->next;
	if (!ft_is_num((char*)in->content))
		ft_error("First input not number of ants");
	in = in->next;
	if (!in || (!is_room((char*)in->content) && !is_start((char*)in->content) &&
		!is_end((char*)in->content)))
		ft_error("Room input error right after number of ants");
	while (in && (is_room((char*)in->content) || is_comment((char*)in->content)
		|| is_start((char*)in->content) || is_end((char*)in->content)))
		in = in->next;
	// if (!in || (!is_comment((char*)in->content) &&
	// 	!is_link((char*)in->content)))
	// 	ft_error("Link input error right after rooms");
	while (in && (is_link((char*)in->content) ||
		is_comment((char*)in->content)))
		in = in->next;
	if (!in)
		return (1);
	return (0);
}
