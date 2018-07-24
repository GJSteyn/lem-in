/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:51:18 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/24 09:00:16 by gsteyn           ###   ########.fr       */
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

int         is_room(char *str)
{
    char    **split;
    int     i;

    split = ft_strsplit(str, ' ');
    i = 0;
    while (split[i])
        i++;
    if (i != 3)
    {
        ft_strldel(&split);
        return (0);
    }
    if (!ft_is_num(split[1]) || !ft_is_num(split[2]))
    {
        ft_strldel(&split);
        return (0);
    }
    ft_strldel(&split);
    return (1);
}

int         is_link(char *str)
{
    char    **split;
    int     i;

    split = ft_strsplit(str, '-');
    i = 0;
    while (split[i])
        i++;
    if (i != 2)
    {
        ft_strldel(&split);
        return (0);
    }
    if (!ft_is_num(split[0]) || !ft_is_num(split[1]))
    {
        ft_strldel(&split);
        return (0);
    }
    ft_strldel(&split);
    return (1);
}