/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 21:10:10 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 19:30:44 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_links		*create_link_node(t_input *input, t_links *link_tmp)
{
	t_links		*link_node;

	link_node = (t_links *)malloc(sizeof(t_links));
	link_node->ind_link = 0;
	link_node->src = link_tmp->src;
	link_node->dst = link_tmp->dst;
	link_node->ind_src = find_ind_room(input, link_tmp->src);
	link_node->ind_dst = find_ind_room(input, link_tmp->dst);
	link_node->next = NULL;
	return (link_node);
}

void		get_link(t_input *input, t_links *link_tmp)
{
	t_links		*link;

	link = create_link_node(input, link_tmp);
	if (!input->start_room && !input->end_room)
		printf("No start/end point in the program");
	if (!input->connect)
	{
		input->connect = link;
	}
	else
	{
		link->ind_link = input->connect->ind_link + 1;
		link->next = input->connect;
		input->connect = link;
	}
}

int			check_dubbing_link(t_input *input, char *room_name1, \
												char *room_name2)
{
	t_links		*tmp;

	tmp = input->connect;
	while (tmp)
	{
		if (!ft_strcmp(room_name1, tmp->src) && \
				!ft_strcmp(room_name2, tmp->dst))
			error("dubbing link");
		if (!ft_strcmp(room_name1, tmp->dst) && \
				!ft_strcmp(room_name2, tmp->src))
			error("dubbing reverse link");
		tmp = tmp->next;
	}
	return (0);
}

void		error(char *reason)
{
	ft_printf("Error: %s\n", reason);
	exit(1);
}
