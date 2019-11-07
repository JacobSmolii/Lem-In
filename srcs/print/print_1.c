/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:17:12 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 19:36:34 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	print_room_list(t_input *input)
{
	t_rooms		*tmp;

	tmp = input->vertex;
	if (!input)
		printf("INPUT ERROR");
	else
	{
		if (!input->vertex)
			printf("ROOM LIST IS EMPTY");
		else
		{
			printf("\n");
			while (tmp)
			{
				printf("ind %d, name %s\n", tmp->ind_room, tmp->name_room);
				tmp = tmp->next;
			}
		}
	}
	printf("\n");
}

void	print_link_list(t_input *input)
{
	t_links		*tmp;

	tmp = input->connect;
	while (tmp)
	{
		printf("int_link %3d,    '%s' [%2d] ----- '%s' [%2d]\n",\
		tmp->ind_link, tmp->src, tmp->ind_src, tmp->dst, tmp->ind_dst);
		tmp = tmp->next;
	}
}

void	print_array(int *array, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		printf("%d,", array[i]);
		i++;
	}
	printf("\n");
}

void	print_path(t_adjlist *path)
{
	int				i;
	int				len;
	t_adjlist		*tmp_path;
	t_adjlistnode	*tmp_width;

	i = 1;
	tmp_path = path;
	if (!path)
		printf("input path = NULL\n");
	while (tmp_path)
	{
		len = 0;
		printf("%d. ", i);
		if (tmp_path)
			printf("%6s [%2d]", tmp_path->room, tmp_path->ind_room);
		tmp_width = tmp_path->head;
		print_path_continue(tmp_width, &len);
		i++;
		printf("\nlen of PATH: [%d]\n", len);
		tmp_path = tmp_path->next;
	}
}

void	print_path_continue(t_adjlistnode *tmp_width, int *len)
{
	while (tmp_width)
	{
		if (tmp_width)
			printf(" -> %s[%2d]", tmp_width->dst, tmp_width->ind_link);
		else
			printf("NULL");
		(*len)++;
		tmp_width = tmp_width->next;
	}
}
