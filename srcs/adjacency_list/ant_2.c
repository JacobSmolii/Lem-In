/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:53:55 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 19:40:02 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void				rev_array(t_lists *lists)
{
	int		i;
	int		buf;

	i = 0;
	buf = 0;
	while (i < lists->nbr_paths / 2)
	{
		buf = lists->paths_length[i];
		lists->paths_length[i] = lists->paths_length[lists->nbr_paths - 1 - i];
		lists->paths_length[lists->nbr_paths - 1 - i] = buf;
		i++;
	}
}

void				fill_path_len(t_lists *lists)
{
	t_adjlist		*tmp_list;

	lists->nbr_paths = 0;
	tmp_list = lists->paths;
	while (tmp_list)
	{
		lists->nbr_paths++;
		tmp_list = tmp_list->next;
	}
	lists->paths_length = (int *)malloc(sizeof(int) * lists->nbr_paths);
	init_array(lists->paths_length, lists->nbr_paths);
	put_len_in_array(lists);
	rev_array(lists);
}

void				put_len_in_array(t_lists *lists)
{
	int				i;
	t_adjlist		*tmp_list;

	i = 0;
	tmp_list = lists->paths;
	while (tmp_list)
	{
		lists->paths_length[i] = len_of_adj_list_node(tmp_list->head);
		i++;
		tmp_list = tmp_list->next;
	}
}

t_adjlistnode		*copy_adjlistnode(t_adjlistnode *template)
{
	t_adjlistnode *tmp;
	t_adjlistnode *final;

	final = NULL;
	while (template)
	{
		if (!final)
			final = create_adj_node(template->dst, template->ind_link);
		else
		{
			tmp = final;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = create_adj_node(template->dst, template->ind_link);
		}
		template = template->next;
	}
	return (final);
}
