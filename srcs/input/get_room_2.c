/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:42:08 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 19:33:01 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_rooms		*init_room_tmp(void)
{
	t_rooms		*room_tmp;

	room_tmp = (t_rooms *)malloc(sizeof(t_rooms));
	room_tmp->cord_x = -5;
	room_tmp->cord_y = -5;
	room_tmp->name_room = NULL;
	room_tmp->ind_room = 0;
	room_tmp->next = NULL;
	return (room_tmp);
}

int			check_room(char *line, t_input *input, t_rooms **room_tmp)
{
	char	*start;

	(*room_tmp) = init_room_tmp();
	start = line;
	while (*line)
		line++;
	line--;
	check_room_coords(input, line, start, (*room_tmp));
	if (!check_dubbing_coord(input, (*room_tmp)) \
		&& !check_dubbing_room_name(input, (*room_tmp)->name_room) \
		&& !check_cap_l_hash((*room_tmp)))
	{
		return (0);
	}
	else
		error("FOUND DOUBLE room name");
	return (1);
}

void		get_room(t_input *input, t_rooms *room_tmp)
{
	t_rooms				*room_node;

	room_node = create_room_node(room_tmp);
	free(room_tmp);
	if (!input->vertex)
		input->vertex = room_node;
	else
	{
		room_node->ind_room = input->vertex->ind_room + 1;
		room_node->next = input->vertex;
		input->vertex = room_node;
	}
	if (input->start_flag == 1)
	{
		input->start_room = room_node;
		input->start_flag--;
	}
	if (input->end_flag == 1)
	{
		input->end_room = room_node;
		input->end_flag--;
	}
}

int			check_dubbing_room_name(t_input *input, char *room_name)
{
	t_rooms		*tmp;

	tmp = input->vertex;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name_room, room_name))
			return (1);
		else
			tmp = tmp->next;
	}
	return (0);
}

int			check_dubbing_coord(t_input *input, t_rooms *room_tmp)
{
	t_rooms		*tmp;

	tmp = input->vertex;
	while (tmp)
	{
		if ((tmp->cord_x == room_tmp->cord_x && tmp->cord_y == \
				room_tmp->cord_y) || (room_tmp->cord_x < 0 || \
										room_tmp->cord_y < 0))
			error("Error coords");
		else
			tmp = tmp->next;
	}
	return (0);
}
