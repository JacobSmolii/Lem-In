/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_edges.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:32:02 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 19:41:28 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	add_edges(t_graph *graph, t_input *input)
{
	t_links		*tmp;

	tmp = input->connect;
	add_dst(graph, tmp);
	add_src(graph, tmp);
}

void	add_src(t_graph *graph, t_links *tmp)
{
	t_adjlist		*adj_list_tmp;
	t_adjlistnode	*new_node;

	while (tmp)
	{
		new_node = create_adj_node(tmp->src, tmp->ind_src);
		adj_list_tmp = graph->list;
		while (adj_list_tmp)
		{
			if (tmp->ind_src == tmp->ind_dst)
				break ;
			if (adj_list_tmp->ind_room == tmp->ind_dst)
			{
				new_node->next = adj_list_tmp->head;
				adj_list_tmp->head = new_node;
				break ;
			}
			adj_list_tmp = adj_list_tmp->next;
		}
		tmp = tmp->next;
	}
}

void	add_dst(t_graph *graph, t_links *tmp)
{
	t_adjlist		*adj_list_tmp;
	t_adjlistnode	*new_node;

	while (tmp)
	{
		new_node = create_adj_node(tmp->dst, tmp->ind_dst);
		adj_list_tmp = graph->list;
		while (adj_list_tmp)
		{
			if (adj_list_tmp->ind_room == tmp->ind_src)
			{
				if (!adj_list_tmp->head)
					adj_list_tmp->head = new_node;
				else
				{
					new_node->next = adj_list_tmp->head;
					adj_list_tmp->head = new_node;
				}
				break ;
			}
			adj_list_tmp = adj_list_tmp->next;
		}
		tmp = tmp->next;
	}
}

void	init_array(int *array, int len)
{
	int		i;

	i = 0;
	while (len > 0)
	{
		array[i] = 0;
		i++;
		len--;
	}
}

void	clean_array(int *array, int len)
{
	int i;

	i = 0;
	while (len > 0)
	{
		if (array[i] < 0)
		{
			array[i] = 0;
		}
		i++;
		len--;
	}
}
