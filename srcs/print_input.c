/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 13:35:23 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/28 13:37:09 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_input(t_list *input)
{
	while (input)
	{
		ft_putstr_fd((char*)input->content, 1);
		input = input->next;
	}
}
