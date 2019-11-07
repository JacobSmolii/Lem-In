/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:58:49 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 19:42:47 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_graph		*create_graph(t_input *input, t_lists *lists)
{
	t_graph		*graph;
	t_adjlist	*new_adj_list;
	t_rooms		*tmp_rooms;

	tmp_rooms = input->vertex;
	lists->nbr_ant = input->nbr_ant;
	init_graph(&graph);
	create_array(input, graph);
	while (tmp_rooms)
	{
		new_adj_list = create_adj_list_node(tmp_rooms->name_room, \
												tmp_rooms->ind_room);
		if (graph->list == NULL)
			graph->list = new_adj_list;
		else
		{
			new_adj_list->next = graph->list;
			graph->list = new_adj_list;
		}
		get_start_end(input, graph, new_adj_list);
		tmp_rooms = tmp_rooms->next;
	}
	return (graph);
}

void		init_graph(t_graph **graph)
{
	(*graph) = (t_graph *)malloc(sizeof(t_graph));
	(*graph)->list = NULL;
	(*graph)->array = NULL;
	(*graph)->start = NULL;
	(*graph)->end = NULL;
}

void		create_array(t_input *input, t_graph *graph)
{
	graph->arr_counter = input->vertex->ind_room + 1;
	graph->array = (int *)malloc(sizeof(int) * ((input->vertex->ind_room) + 1));
	init_array(graph->array, graph->arr_counter);
}

void		get_start_end(t_input *input, t_graph *graph, \
									t_adjlist *new_adj_list)
{
	if (new_adj_list->ind_room == input->start_room->ind_room)
		graph->start = new_adj_list;
	if (new_adj_list->ind_room == input->end_room->ind_room)
		graph->end = new_adj_list;
}

t_adjlist	*create_adj_list_node(char *name_room, int index)
{
	t_adjlist		*new_node;

	new_node = (t_adjlist *)malloc(sizeof(t_adjlist));
	new_node->ind_room = index;
	new_node->room = ft_strdup(name_room);
	new_node->head = NULL;
	new_node->next = NULL;
	return (new_node);
}
