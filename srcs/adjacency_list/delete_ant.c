/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_ant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:51:43 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 19:41:22 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	del_ant(t_ant **ants_list)
{
	if (!(*ants_list)->next && !(*ants_list)->prev)
		del_single_ant(ants_list);
	else if (!(*ants_list)->next)
		del_last_ant(ants_list);
	else if ((*ants_list)->next && (*ants_list)->prev)
		del_middle_ant(ants_list);
	else if ((*ants_list)->next && !(*ants_list)->prev)
		del_first_ant(ants_list);
}

void	del_first_ant(t_ant **ants_list)
{
	t_ant		*buf;

	buf = NULL;
	buf = (*ants_list)->next;
	(*ants_list)->next->prev = NULL;
	(*ants_list)->next = NULL;
	free(*ants_list);
	(*ants_list) = buf;
}

void	del_middle_ant(t_ant **ants_list)
{
	t_ant		*tmp;
	t_ant		*buf;

	buf = NULL;
	tmp = NULL;
	buf = (*ants_list);
	tmp = (*ants_list)->next;
	(*ants_list)->next->prev = (*ants_list)->prev;
	(*ants_list)->prev->next = (*ants_list)->next;
	free(buf);
	(*ants_list) = tmp;
}

void	del_last_ant(t_ant **ants_list)
{
	t_ant		*buf;

	buf = NULL;
	buf = (*ants_list)->prev;
	(*ants_list)->prev = NULL;
	buf->next = NULL;
	free((*ants_list));
}

void	del_single_ant(t_ant **ants_list)
{
	free((*ants_list));
	(*ants_list) = NULL;
}
