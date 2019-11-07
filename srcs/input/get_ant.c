/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ant.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:56:29 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 19:29:53 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		check_ant_num(char *line)
{
	char	*start;

	start = line;
	while (*line)
		line++;
	line--;
	while (line >= start)
	{
		if (!(*line >= '0' && *line <= '9'))
		{
			error("No correct ant");
			return (1);
		}
		if (line != start)
			line--;
		else
			break ;
	}
	return (0);
}

void	get_ant(t_input *input, char *line)
{
	int		nbr;

	nbr = ft_atoi(line);
	input->nbr_ant = nbr;
	if (input->nbr_ant == 0)
		error("Zero is not valid for ants");
	else
		input->faze++;
}

void	start_check(t_input *input, char *line)
{
	if (!ft_strcmp(line, "##start"))
	{
		if (input->start_room != NULL)
			error("Double start");
		else
			input->start_flag++;
	}
}

void	end_check(t_input *input, char *line)
{
	if (!ft_strcmp(line, "##end"))
	{
		if (input->end_room != NULL)
			error("Double end");
		else
			input->end_flag++;
	}
}

int		check_line(char *line)
{
	if ((line == NULL || *line == '\n' || *line == '\0'))
		return (1);
	return (0);
}
