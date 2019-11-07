/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:55:56 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 20:39:30 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(void)
{
	int			fd;
	char		*line;
	t_input		input;

	fd = 0;
	ft_bzero(&input, sizeof(t_input));
	while (get_next_line(fd, &line) > 0)
		start_work(line, &input);
	main_2(&input);
	return (0);
}

void	main_2(t_input *input)
{
	int			n;
	t_lists		lists;
	t_graph		*graph;

	n = 1;
	ft_bzero(&lists, sizeof(t_lists));
	graph = create_graph(input, &lists);
	add_edges(graph, input);
	lists.working = init_path(graph);
	find_paths(&graph, &lists);
	print_result(lists.rest, (lists.nbr_paths + 3), lists.paths_length);
	display_ant_ant(&lists, &n);
}

/*
** this is for checking our graph
** after line
** 38 - print_graph(graph);
** 40 - print_graph(graph);
** 43 - print_path(lists.paths);
*/
