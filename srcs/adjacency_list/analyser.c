/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 19:26:58 by ititkov           #+#    #+#             */
/*   Updated: 2019/07/18 19:38:38 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	fill_paths(t_lists *lists, int i, int *nbr_ant)
{
	init_fill_path(lists, nbr_ant, i);
	if (lists->quo > 0)
		lists->rest[2]++;
	if (i == lists->rest[0] || lists->quo < (lists->paths_length[lists->l + 1] \
						- lists->paths_length[lists->l]))
	{
		while (i-- > 0)
		{
			lists->rest[lists->j] = lists->rest[lists->j] + lists->quo;
			*nbr_ant = *nbr_ant - lists->quo;
			fill_path_while_if(lists, nbr_ant);
			lists->l++;
		}
	}
	else
	{
		while (i > 0)
		{
			fill_path_else(lists, nbr_ant);
			i--;
		}
	}
}

void	init_fill_path(t_lists *lists, int *nbr_ant, int i)
{
	lists->quo = 0;
	lists->rem = 0;
	lists->j = 3;
	lists->l = i - 1;
	lists->quo = *nbr_ant / i;
	lists->rem = *nbr_ant % i;
}

void	fill_path_while_if(t_lists *lists, int *nbr_ant)
{
	if (lists->rem > 0)
	{
		lists->rest[lists->j]++;
		lists->rem--;
		(*nbr_ant)--;
	}
	lists->j++;
}

void	fill_path_else(t_lists *lists, int *nbr_ant)
{
	lists->rest[lists->j] += (lists->paths_length[lists->l + 1] \
							- lists->paths_length[lists->l]);
	*nbr_ant = *nbr_ant - (lists->paths_length[lists->l + 1] - \
							lists->paths_length[lists->l]);
	lists->j++;
}

void	analyser(t_lists *lists)
{
	int			i;
	int			j;
	int			nbr_ant;

	j = 0;
	i = 1;
	nbr_ant = lists->nbr_ant;
	lists->nbr_paths = len_adj_list(lists->paths);
	lists->rest = (int *)malloc(sizeof(int) * (lists->nbr_paths + 4));
	init_array(lists->rest, (lists->nbr_paths + 4));
	lists->rest[j++] = lists->nbr_paths;
	lists->rest[j++] = nbr_ant;
	while (i <= lists->nbr_paths)
	{
		fill_paths(lists, i, &nbr_ant);
		i++;
	}
	lists->rest[lists->nbr_paths + 3] = lists->rest[3] + \
							lists->paths_length[0] - 1;
	if (lists->rest[lists->nbr_paths + 2] == 0)
		lists->overpath = 1;
}
