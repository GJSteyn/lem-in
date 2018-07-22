/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.wethinkcode.co.z    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:16:39 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/22 13:16:41 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lem-in.h"
#include "get_next_line.h"
#include "libft.h"

static int         is_comment(char *str)
{
    if (ft_strlen(str) < 2)
        return (0);
    else if (str[0] == '#' && str[1] != '#')
        return (1);
    else
        return (0);
}

static int         is_start(char *str)
{
    if (ft_strcmp(str, "##start" == 0))
        return (1);
    else
        return (0);
}

static int         is_end(char *str)
{
    if (ft_strcmp(str, "##end" == 0))
        return (1);
    else
        return (0);
}

void               parse_map(t_state *state)
{
    char    *in;
    int     line_num;
    int     start;
    int     end;

    line_num = 0;
    while (get_next_line(0, &in) > 0)
    {
        if (is_comment(in))
        {
            ft_strdel(&in);
            continue ;
        }
        if (line_num++ == 0 && ft_is_num(in))
            state->num_ants = ft_atoi(in);
    }
}