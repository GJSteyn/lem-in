/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:51:18 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/23 12:01:49 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int         is_end(char *str)
{
    if (ft_strcmp(str, "##end") == 0)
        return (1);
    return (0);
} 

int         is_start(char *str)
{
    if (ft_strcmp(str, "##start") == 0)
        return (1);
    return (0);
}

int         is_comment(char *str)
{
    int         strlen;

    strlen = ft_strlen(str);
    if (strlen == 0)
        return (0);
    if (strlen < 2)
        if (str[0] == '#')
            return (1);
    if (str[0] == '#' && str[1] != '#')
        return (1);
    return (0);
}