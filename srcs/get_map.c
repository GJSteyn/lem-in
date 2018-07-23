/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:14:24 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/23 09:24:50 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"
#include "get_next_line.h"

t_list          *get_map(void)
{
    char        *in;
    t_list      *ret;

    while (get_next_line(0, &in) > 0)
        ft_lstappend(&ret, ft_lstnew(in, ft_strlen(in)));
    return (ret);
}