/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:38:29 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 19:43:50 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int				len_of_adj_list_node(t_adjlistnode *links)
{
	int				len;
	t_adjlistnode	*tmp;

	len = 0;
	tmp = links;
	if (!tmp)
		return (0);
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void			remove_first_path(t_adjlist **path)
{
	t_adjlist		*buf;

	buf = NULL;
	del_adj_list_node(&(*path)->head, 0);
	buf = (*path)->next;
	free((*path));
	(*path) = buf;
}

void			del_path(t_adjlist **path, int ind)
{
	t_adjlist		*buf;
	t_adjlist		*tmp_path;
	t_adjlistnode	*tmp_node;

	while ((*path) && (*path)->head->ind_link == ind)
		remove_first_path(path);
	tmp_path = (*path);
	while (tmp_path && tmp_path->next)
	{
		tmp_node = tmp_path->next->head;
		if (tmp_path->next->ind_room == ind)
		{
			del_adj_list_node(&tmp_node, 0);
			buf = tmp_path->next;
			tmp_path->next = tmp_path->next->next;
			free(buf);
		}
		else
			tmp_path = tmp_path->next;
	}
}

void			del_adj_list_node(t_adjlistnode **link_list, int len)
{
	int					i;
	t_adjlistnode		*tmp;
	t_adjlistnode		*buf;

	i = 0;
	buf = NULL;
	tmp = (*link_list);
	while (tmp)
	{
		if (i <= len)
			break ;
		i++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		buf = tmp->next;
		free(tmp);
		tmp = buf;
	}
	if (len == 0)
		(*link_list) = NULL;
}

t_adjlistnode	*create_adj_node(char *dst, int index)
{
	t_adjlistnode	*new_node;

	new_node = (t_adjlistnode *)malloc(sizeof(t_adjlistnode));
	new_node->dst = ft_strdup(dst);
	new_node->ind_link = index;
	new_node->next = NULL;
	return (new_node);
}
