/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:46:03 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 20:11:11 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void		add_link_to_path(t_graph *graph, t_adjlist *next_path, \
					t_adjlistnode *unvisited_links, t_lists *lists)
{
	t_adjlist		*path_tmp;
	t_adjlistnode	*links_tmp;
	t_adjlistnode	*node;

	path_tmp = next_path;
	links_tmp = unvisited_links;
	node = NULL;
	while (path_tmp)
	{
		node = create_adj_node(links_tmp->dst, links_tmp->ind_link);
		add_link_to_path_cont(path_tmp, node);
		graph->array[links_tmp->ind_link] = -1;
		if (graph->end->ind_room == links_tmp->ind_link)
		{
			collect_found_path(&path_tmp, lists);
			return ;
		}
		links_tmp = links_tmp->next;
		path_tmp = path_tmp->next;
	}
}

t_adjlist	*create_adj_path_node(t_adjlist *path_tmp)
{
	t_adjlist		*new_node;

	new_node = (t_adjlist *)malloc(sizeof(t_adjlist));
	new_node->ind_room = path_tmp->ind_room;
	new_node->room = ft_strdup(path_tmp->room);
	new_node->head = copy_adjlistnode(path_tmp->head);
	new_node->next = NULL;
	return (new_node);
}

void		add_link_to_path_cont(t_adjlist *path_tmp, t_adjlistnode *node)
{
	t_adjlistnode	*node_tmp;

	node_tmp = NULL;
	if (!path_tmp->head)
		path_tmp->head = node;
	else
	{
		node_tmp = path_tmp->head;
		while (node_tmp->next)
			node_tmp = node_tmp->next;
		node_tmp->next = node;
	}
}

void		reverse(t_adjlist **path)
{
	t_adjlist	*rev;
	t_adjlist	*new;
	t_adjlist	*tmp;

	new = NULL;
	rev = NULL;
	tmp = (*path);
	while (tmp)
	{
		new = create_adj_path_node(tmp);
		if (!rev)
			rev = new;
		else
		{
			new->next = rev;
			rev = new;
		}
		tmp = tmp->next;
	}
	delete_adjlist((*path));
	(*path) = rev;
}

t_adjlist	*copy_path(t_adjlist *path, int len)
{
	t_adjlist	*path_tmp;
	t_adjlist	*head;
	t_adjlist	*new;

	head = NULL;
	new = NULL;
	path_tmp = path;
	head = create_adj_path_node(path_tmp);
	len--;
	while (len > 0)
	{
		new = create_adj_path_node(path_tmp);
		new->next = head;
		head = new;
		len--;
	}
	return (head);
}
