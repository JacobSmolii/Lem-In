/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:58:08 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 19:27:51 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void		check_room_coords(t_input *input, char *line, char *start, \
													t_rooms *room_tmp)
{
	int		flag;

	flag = 0;
	while (line != start)
	{
		if (*line >= '0' && *line <= '9')
		{
			if (get_coords_room(room_tmp, line, *(line - 1), &flag))
				break ;
		}
		else
		{
			if (check_space_in_room(input, (*line), (*line + 1)))
				return ;
		}
		line--;
	}
	if (((line - 1) - start) == 0 || room_tmp->cord_x < 0)
		error("No rooms");
	else
		room_tmp->name_room = ft_strsub(start, 0, ((line - 1) - start));
}

int			check_space_in_room(t_input *input, char space, char space_or_line)
{
	if (space == ' ')
	{
		if (space_or_line == ' ')
			error("Overspace");
		else if (space_or_line == '\0')
			error("Coords");
	}
	else
	{
		input->faze = 2;
		return (1);
	}
	return (0);
}

int			get_coords_room(t_rooms *room_tmp, char *line, char prev, int *flag)
{
	if (prev == ' ')
	{
		if (*flag == 0)
		{
			room_tmp->cord_y = ft_atoi(line);
			(*flag)++;
		}
		else
		{
			room_tmp->cord_x = ft_atoi(line);
			return (1);
		}
	}
	return (0);
}

int			check_cap_l_hash(t_rooms *room_tmp)
{
	if (!room_tmp->name_room)
		error("Room name is empty");
	if (*room_tmp->name_room == 'L' || *room_tmp->name_room == '#')
	{
		error("Uncorrect name of room(L || #)");
		return (1);
	}
	return (0);
}

t_rooms		*create_room_node(t_rooms *room_tmp)
{
	t_rooms		*room_node;

	room_node = (t_rooms *)malloc(sizeof(t_rooms) * 1);
	room_node->ind_room = 0;
	room_node->cord_x = room_tmp->cord_x;
	room_node->cord_y = room_tmp->cord_y;
	room_node->name_room = room_tmp->name_room;
	room_node->next = NULL;
	return (room_node);
}
