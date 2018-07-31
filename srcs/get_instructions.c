/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 05:59:30 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/31 09:50:54 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int				is_instruction(char *line)
{
	if (ft_strlen(line) < 4)
		return (0);
	if (line[0] != 'L')
		return (0);
	return (1);
}

t_list			*get_instructions(t_list *input)
{
	char	**split;
	int		i;
	t_list	*ret;
	t_list	*new;

	ret = NULL;
	if (!input)
		return (NULL);
	while (!is_instruction((char*)input->content))
		input = input->next;
	while (input)
	{
		i = 0;
		split = ft_strsplit((char*)input->content, ' ');
		while (split[i])
		{
			new = ft_lstnew(split[i], ft_strlen(split[i]) + 1);
			ft_lstappend(&ret, new);
			i++;
		}
		input = input->next;
	}
	return (ret);
}
