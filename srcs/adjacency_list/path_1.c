/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:15:35 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 19:46:54 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_adjlist			*init_path(t_graph *graph)
{
	t_adjlist			*path;

	path = NULL;
	path = create_adj_list_node(graph->start->room, graph->start->ind_room);
	graph->array[graph->start->ind_room] = 1;
	return (path);
}

void				find_paths(t_graph **graph, t_lists *lists)
{
	t_adjlist		*path;

	path = lists->working;
	path_next_step(graph, &path, lists);
	delete_adjlist(lists->working);
	if ((*graph)->array[(*graph)->end->ind_room] == 0)
	{
		lists->working = path;
		if (lists->working)
			find_paths(graph, lists);
		else
		{
			reverse(&lists->paths);
			return ;
		}
	}
	else
		find_path_else(graph, lists);
}

void				find_path_else(t_graph **graph, t_lists *lists)
{
	put_way_in_array((*graph), lists);
	lists->working = init_path((*graph));
	if (len_adj_list(lists->paths) >= 1)
	{
		fill_path_len(lists);
		analyser(lists);
		if (lists->overpath == 1)
		{
			reverse(&lists->paths);
			return ;
		}
	}
	if (lists->working)
		find_paths(graph, lists);
	else
	{
		reverse(&lists->paths);
		return ;
	}
}

void				join_path(t_adjlist **set_path, t_adjlist *next_path)
{
	t_adjlist		*tmp_path;

	if (!(*set_path))
		(*set_path) = next_path;
	else
	{
		tmp_path = (*set_path);
		while (tmp_path->next)
			tmp_path = tmp_path->next;
		tmp_path->next = next_path;
	}
}

t_adjlistnode		*check_visit(t_graph *graph, t_adjlist *list_tmp)
{
	t_adjlistnode	*node_tmp;
	t_adjlistnode	*unvisited_links;
	t_adjlistnode	*new_node;

	unvisited_links = NULL;
	node_tmp = list_tmp->head;
	while (node_tmp)
	{
		if (graph->array[node_tmp->ind_link] == 0)
		{
			if (!unvisited_links)
				unvisited_links = create_adj_node(node_tmp->dst, \
												node_tmp->ind_link);
			else
			{
				new_node = create_adj_node(node_tmp->dst, node_tmp->ind_link);
				new_node->next = unvisited_links;
				unvisited_links = copy_adjlistnode(new_node);
				delete_adjlistnode(new_node);
			}
		}
		node_tmp = node_tmp->next;
	}
	return (unvisited_links);
}
