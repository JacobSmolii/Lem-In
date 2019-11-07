/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:20:34 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 19:39:08 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	display_ant_ant(t_lists *lists, int *n)
{
	display_ant(&lists, n);
}

void	display_ant(t_lists **lists, int *n)
{
	int				i;
	t_ant			*ant;
	t_ant			*set_ants;
	t_adjlist		*tmp_node;

	i = 3;
	ant = NULL;
	set_ants = (*lists)->ants;
	tmp_node = (*lists)->paths;
	while (i < (*lists)->nbr_paths + 3)
	{
		if ((*lists)->rest[i] == 0)
			break ;
		ant = create_ant_node(n, tmp_node->head);
		tmp_node = tmp_node->next;
		(*lists)->rest[i]--;
		add_ant_node(ant, &set_ants);
		i++;
	}
	(*lists)->ants = set_ants;
	print_ants(lists);
	if (!set_ants)
		return ;
	display_ant(lists, n);
}

t_ant	*create_ant_node(int *ant_ind, t_adjlistnode *path)
{
	t_ant		*new_ant;

	new_ant = (t_ant *)malloc(sizeof(t_ant));
	new_ant->ant_ind = *ant_ind;
	(*ant_ind)++;
	new_ant->ant_path = copy_adjlistnode(path);
	new_ant->next = NULL;
	new_ant->prev = NULL;
	return (new_ant);
}

void	add_ant_node(t_ant *ant, t_ant **ants_list)
{
	if (!(*ants_list))
		(*ants_list) = ant;
	else
	{
		ant->next = (*ants_list);
		(*ants_list)->prev = ant;
		(*ants_list) = ant;
	}
}
