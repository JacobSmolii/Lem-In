/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 21:24:12 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 19:44:52 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	collect_found_path(t_adjlist **path_tmp, t_lists *lists)
{
	t_adjlist	*head;

	head = NULL;
	head = create_adj_path_node((*path_tmp));
	if (!lists->paths)
		lists->paths = head;
	else
	{
		head->next = lists->paths;
		lists->paths = head;
	}
}

void	put_way_in_array(t_graph *graph, t_lists *lists)
{
	int					i;
	t_adjlist			*tmp_list;
	t_adjlistnode		*tmp;

	i = 0;
	tmp = lists->paths->head;
	tmp_list = lists->paths;
	clean_array(graph->array, graph->arr_counter);
	while (tmp_list)
	{
		i++;
		tmp_list = tmp_list->next;
	}
	while (tmp)
	{
		graph->array[tmp->ind_link] = i;
		tmp = tmp->next;
	}
	graph->array[graph->end->ind_room] = 0;
}

int		len_adj_list(t_adjlist *paths)
{
	int				len;
	t_adjlist		*paths_tmp;

	len = 0;
	paths_tmp = paths;
	while (paths_tmp)
	{
		len++;
		paths_tmp = paths_tmp->next;
	}
	return (len);
}

void	delete_adjlistnode(t_adjlistnode *list)
{
	if (!list)
		return ;
	if (list->next)
		delete_adjlistnode(list->next);
	free(list->dst);
	free(list);
}

void	delete_adjlist(t_adjlist *list)
{
	if (!list)
		return ;
	if (list->next)
		delete_adjlist(list->next);
	delete_adjlistnode(list->head);
	free(list->room);
	free(list);
}
