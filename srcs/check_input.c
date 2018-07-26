/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.wethinkcode.co.z    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:39:13 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/26 09:11:41 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int		valid_line(char *line)
{
	if (ft_strlen(line) == 0)
		return (0);
	if (is_comment(line) || is_room(line) || is_end(line) || is_start(line) ||
		is_link(line) || is_command(line))
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

int				valid_input(t_list *in)
{
	check_all_valid(in);
	while (is_comment((char*)in->content))
		in = in->next;
	if (!ft_is_num((char*)in->content))
		ft_error("First input not number of ants");
	in = in->next;
	if (!in || !is_room((char*)in->content) || !is_start((char*)in->content) ||
		!is_end((char*)in->content))
		ft_error("Room input error right after number of ants");
	while (in && (is_room((char*)in->content) || is_comment((char*)in->content)
		|| is_start((char*)in->content) || is_end((char*)in->content)))
		in = in->next;
	if (!in || !is_comment((char*)in->content) || !is_link((char*)in->content))
		ft_error("Link input error right after rooms");
	while (in && (is_link((char*)in->content) ||
		is_comment((char*)in->content)))
		in = in->next;
	if (!in)
		return (1);
	return (0);
}
