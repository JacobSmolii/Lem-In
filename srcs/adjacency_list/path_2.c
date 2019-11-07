/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:42:08 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 20:12:29 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_adjlist		*next_step_first_node(t_graph **graph, t_adjlist *list_tmp, \
											t_adjlist **path, t_lists *lists)
{
	int				len;
	t_adjlist		*next_path;
	t_adjlistnode	*unvisited_links;

	len = 0;
	next_path = NULL;
	while (list_tmp)
	{
		if (list_tmp->ind_room == (*path)->ind_room)
		{
			unvisited_links = check_visit((*graph), list_tmp);
			if (!unvisited_links)
				return (NULL);
			len = len_of_adj_list_node(unvisited_links);
			next_path = copy_path((*path), len);
			break ;
		}
		list_tmp = list_tmp->next;
	}
	if (list_tmp)
	{
		add_link_to_path((*graph), next_path, unvisited_links, lists);
		delete_adjlistnode(unvisited_links);
	}
	return (next_path);
}

int				init_step_next(t_adjlist *list_tmp, int len)
{
	if (len == 0)
	{
		list_tmp = list_tmp->next;
		return (1);
	}
	return (0);
}

t_adjlistnode	*find_end(t_adjlist *path)
{
	t_adjlistnode	*tmp;

	tmp = path->head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_adjlist		*next_step_next_node(t_graph *graph, t_adjlist *list_tmp, \
										t_adjlist **path, t_lists *lists)
{
	int				len;
	t_adjlist		*next_path;
	t_adjlistnode	*tmp;
	t_adjlistnode	*unvisited_links;

	len = 0;
	next_path = NULL;
	tmp = find_end((*path));
	while (list_tmp)
	{
		if (list_tmp->ind_room == tmp->ind_link)
		{
			unvisited_links = check_visit(graph, list_tmp);
			len = len_of_adj_list_node(unvisited_links);
			if (init_step_next(list_tmp, len))
				return (NULL);
			next_path = copy_path((*path), len);
			add_link_to_path(graph, next_path, unvisited_links, lists);
			delete_adjlistnode(unvisited_links);
			break ;
		}
		list_tmp = list_tmp->next;
	}
	return (next_path);
}

void			path_next_step(t_graph **graph, t_adjlist **path, \
													t_lists *lists)
{
	t_adjlist		*set_path;
	t_adjlist		*next_path;

	set_path = NULL;
	while ((*path))
	{
		next_path = NULL;
		if (!(*path)->head)
			next_path = next_step_first_node(graph, (*graph)->list, \
															path, lists);
		else
			next_path = next_step_next_node((*graph), (*graph)->list, \
															path, lists);
		if (next_path)
		{
			join_path(&set_path, next_path);
		}
		(*path) = (*path)->next;
	}
	(*path) = set_path;
}
