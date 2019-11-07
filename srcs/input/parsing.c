/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:29:50 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 19:33:24 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	start_work(char *line, t_input *input)
{
	t_rooms		*room_tmp;
	t_links		link_tmp;

	ft_bzero(&link_tmp, sizeof(t_links));
	if (check_line(line))
		error("Empty string");
	if (comment_check(line) == 1)
	{
		free(line);
		return ;
	}
	if (start_work_continue(input, line, &link_tmp, &room_tmp))
	{
		free(line);
		return ;
	}
	check_faze_2(input, &link_tmp, line);
}

int		start_work_continue(t_input *input, char *line, t_links *link_tmp, \
													t_rooms **room_tmp)
{
	if (input->faze == 0)
	{
		if (!check_ant_num(line))
		{
			get_ant(input, line);
			return (1);
		}
	}
	else if (input->faze == 1)
	{
		if (ft_strcmp(line, "##end") && ft_strcmp(line, "##start") \
								&& !check_link(line, input, link_tmp))
			input->faze = 2;
		else
		{
			if (ft_strcmp(line, "##start") && ft_strcmp(line, "##end") && \
										!check_room(line, input, room_tmp))
				get_room(input, (*room_tmp));
			start_check(input, line);
			end_check(input, line);
			return (1);
		}
	}
	return (0);
}

void	check_faze_2(t_input *input, t_links *link_tmp, char *line)
{
	if (input->faze == 2)
	{
		if (!check_link(line, input, link_tmp))
		{
			if (!input->start_room)
				error("start room doesn't exist");
			if (!input->end_room)
				error("end room doesn't exist");
			get_link(input, link_tmp);
		}
	}
	else
		error("trash line\n");
}
