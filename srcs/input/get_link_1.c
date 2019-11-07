/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:04:20 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 19:29:19 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		check_link(char *line, t_input *input, t_links *link_tmp)
{
	char	*start;
	int		counter;

	counter = 0;
	start = line;
	while (*line)
		line++;
	line--;
	while (line != start)
	{
		if (*line == '-')
			counter++;
		if (*(line - 1) == '-')
			return (continue_check_link(input, link_tmp, start, line - 1));
		else
			check_sec_room(input, *line + 1, *line);
		line--;
	}
	if (counter == 0 && input->faze == 2)
		error("Not correct link input");
	return (1);
}

int		continue_check_link(t_input *input, t_links *link_tmp, \
											char *start, char *line)
{
	char		*str;

	str = NULL;
	link_tmp->dst = line + 1;
	if (check_dubbing_room_name(input, link_tmp->dst))
	{
		str = ft_strsub(start, 0, (line - start));
		if (link_tmp->src)
			free(link_tmp->src);
		link_tmp->src = ft_strdup(str);
		free(str);
		if (check_dubbing_room_name(input, link_tmp->src))
		{
			if (!check_dubbing_link(input, link_tmp->src, line + 1))
				return (0);
		}
		else
			error("Trash-first-room");
	}
	else
		error("Trash-second-room");
	return (1);
}

void	check_sec_room(t_input *input, char end_line, char dash)
{
	if (end_line == '\0' && input->faze == 2 && dash == '-')
		error("Second room doesn't exist");
}

int		find_ind_room(t_input *input, char *room)
{
	t_rooms			*room_list_tmp;

	room_list_tmp = input->vertex;
	while (room_list_tmp)
	{
		if (!ft_strcmp(room_list_tmp->name_room, room))
			return (room_list_tmp->ind_room);
		else
			room_list_tmp = room_list_tmp->next;
	}
	return (1);
}

int		comment_check(char *line)
{
	if (*line == '#' && *(line + 1) != '#')
		return (1);
	return (0);
}
