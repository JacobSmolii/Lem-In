/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:29:47 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 19:35:44 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	print_graph(t_graph *graph)
{
	t_adjlist		*tmp_list;
	t_adjlistnode	*tmp_node;

	tmp_list = graph->list;
	printf("\ngraph\n\n");
	while (tmp_list)
	{
		if (tmp_list)
			printf("%6s [%2d]    ", tmp_list->room, tmp_list->ind_room);
		tmp_node = tmp_list->head;
		while (tmp_node)
		{
			if (tmp_node)
				printf(" -> %s[%2d]", tmp_node->dst, tmp_node->ind_link);
			else
				printf("NULL");
			tmp_node = tmp_node->next;
		}
		printf("\n");
		tmp_list = tmp_list->next;
	}
}

void	print_result(int *res, int lent, int *array)
{
	int			i;

	i = 0;
	ft_printf("~~~~~~~~~~~~~~~~~~~\n");
	ft_printf("Total paths    %2d\n", res[i++]);
	ft_printf("Total ants     %2d\n", res[i++]);
	ft_printf("Active paths   %2d\n\n", res[i++]);
	while (i < lent)
	{
		ft_printf("Path %2d, Length %2d, Amount of ants %2d\n", \
									(i - 2), array[i - 3], res[i]);
		i++;
	}
	ft_printf("\nSteps          %2d\n\n", res[i++]);
	ft_printf("~~~~~~~~~~~~~~~~~~~\n");
}

void	print_ants(t_lists **lists)
{
	t_adjlistnode	*path_tmp;
	t_ant			*tmp;
	t_ant			*origin;

	path_tmp = NULL;
	tmp = (*lists)->ants;
	origin = (*lists)->ants;
	if (!(*lists)->ants)
	{
		printf("The MAGIC ends here\n");
		return ;
	}
	while ((*lists)->ants && !(*lists)->ants->ant_path)
	{
		del_ant(&(*lists)->ants);
		if (!(*lists)->ants)
			tmp = NULL;
	}
	print_ants_cont(lists, tmp, path_tmp);
	if ((*lists)->ants)
		(*lists)->ants = origin;
	printf("\n");
}

void	print_ants_cont(t_lists **lists, t_ant *tmp, t_adjlistnode *path_tmp)
{
	while (tmp)
	{
		while ((tmp->next) && (!tmp->next->ant_path))
		{
			(*lists)->ants = tmp;
			del_ant(&(*lists)->ants->next);
		}
		printf("L%d-%s ", tmp->ant_ind, tmp->ant_path->dst);
		path_tmp = tmp->ant_path->next;
		free(tmp->ant_path);
		tmp->ant_path = path_tmp;
		tmp = tmp->next;
	}
}
