/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:57:30 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 20:41:22 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

typedef struct	s_adjlistnode
{
	int						ind_link;
	char					*dst;
	struct s_adjlistnode	*next;
}				t_adjlistnode;

typedef struct	s_ant
{
	int						ant_ind;
	t_adjlistnode			*ant_path;
	struct s_ant			*next;
	struct s_ant			*prev;
}				t_ant;

typedef struct	s_adjlist
{
	int						ind_room;
	char					*room;
	t_adjlistnode			*head;
	struct s_adjlist		*next;
}				t_adjlist;

typedef struct	s_graph
{
	int						arr_counter;
	int						*array;
	t_adjlist				*start;
	t_adjlist				*end;
	t_adjlist				*list;
}				t_graph;

typedef struct	s_lists
{
	int						j;
	int						l;
	int						quo;
	int						rem;
	int						nbr_paths;
	int						nbr_ant;
	int						overpath;
	int						*paths_length;
	int						*rest;
	t_adjlist				*working;
	t_adjlist				*paths;
	t_ant					*ants;
}				t_lists;

typedef struct	s_links
{
	int						ind_link;
	int						ind_src;
	int						ind_dst;
	char					*src;
	char					*dst;
	struct s_links			*next;
}				t_links;

typedef struct	s_rooms
{
	int						cord_x;
	int						cord_y;
	int						ind_room;
	char					*name_room;
	struct s_rooms			*next;
}				t_rooms;

typedef struct	s_input
{
	int						nbr_ant;
	int						nbr_room;
	int						faze;
	int						start_flag;
	int						end_flag;
	t_rooms					*start_room;
	t_rooms					*end_room;
	t_rooms					*vertex;
	t_links					*connect;
}				t_input;

int				main(void);
void			main_2(t_input *input);
void			start_work(char *line, t_input *input);
int				start_work_continue(t_input *input, char *line, \
					t_links *link_tmp, t_rooms **room_tmp);
void			check_faze_2(t_input *input, t_links *link_tmp, char *line);
int				check_ant_num(char *line);
void			get_ant(t_input *input, char *line);
void			start_check(t_input *input, char *line);
void			end_check(t_input *input, char *line);
int				check_line(char *line);
void			check_room_coords(t_input *input, char *line, \
							char *start, t_rooms *room_tmp);
int				check_space_in_room(t_input *input, char space, \
												char space_or_line);
int				get_coords_room(t_rooms *room_tmp, char *line, char \
													prev, int *flag);
int				check_cap_l_hash(t_rooms *room_tmp);
t_rooms			*create_room_node(t_rooms *room_tmp);
t_rooms			*init_room_tmp(void);
int				check_room(char *line, t_input *input, t_rooms **room_tmp);
void			get_room(t_input *input, t_rooms *room_tmp);
int				check_dubbing_room_name(t_input *input, char *room_name);
int				check_dubbing_coord(t_input *input, t_rooms *room_tmp);
int				check_link(char *line, t_input *input, t_links *link_tmp);
int				continue_check_link(t_input *input, t_links *link_tmp, \
										char *start, char *line);
void			check_sec_room(t_input *input, char end_line, char dash);
int				find_ind_room(t_input *input, char *room);
int				comment_check(char *line);
t_links			*create_link_node(t_input *input, t_links *link_tmp);
void			get_link(t_input *input, t_links *link_tmp);
int				check_dubbing_link(t_input *input, char *room_name1, \
												char *room_name2);
void			error(char *reason);
t_graph			*create_graph(t_input *input, t_lists *lists);
void			init_graph(t_graph **graph);
void			create_array(t_input *input, t_graph *graph);
void			get_start_end(t_input *input, t_graph *graph, \
									t_adjlist *new_adj_list);
t_adjlist		*create_adj_list_node(char *name_room, int index);
int				len_of_adj_list_node(t_adjlistnode *links);
void			remove_first_path(t_adjlist **path);
void			del_path(t_adjlist **path, int ind);
void			del_adj_list_node(t_adjlistnode **link_list, int len);
t_adjlistnode	*create_adj_node(char *dst, int index);
void			add_edges(t_graph *graph, t_input *input);
void			add_src(t_graph *graph, t_links *tmp);
void			add_dst(t_graph *graph, t_links *tmp);
void			init_array(int *array, int len);
void			clean_array(int *array, int len);
void			del_ant(t_ant **ants_list);
void			del_first_ant(t_ant **ants_list);
void			del_middle_ant(t_ant **ants_list);
void			del_last_ant(t_ant **ants_list);
void			del_single_ant(t_ant **ants_list);
void			rev_array(t_lists *lists);
void			fill_path_len(t_lists *lists);
void			put_len_in_array(t_lists *lists);
t_adjlistnode	*copy_adjlistnode(t_adjlistnode *template);
void			display_ant_ant(t_lists *lists, int *n);
void			display_ant(t_lists **lists, int *n);
t_ant			*create_ant_node(int *ant_ind, t_adjlistnode *path);
void			add_ant_node(t_ant *ant, t_ant **ants_list);
void			rev_array(t_lists *lists);
void			fill_path_len(t_lists *lists);
void			put_len_in_array(t_lists *lists);
t_adjlistnode	*copy_adjlistnode(t_adjlistnode *template);
void			fill_paths(t_lists *lists, int i, int *nbr_ant);
void			init_fill_path(t_lists *lists, int *nbr_ant, int i);
void			fill_path_while_if(t_lists *lists, int *nbr_ant);
void			fill_path_else(t_lists *lists, int *nbr_ant);
void			analyser(t_lists *lists);
t_adjlist		*init_path(t_graph *graph);
void			find_paths(t_graph **graph, t_lists *lists);
void			find_path_else(t_graph **graph, t_lists *lists);
void			join_path(t_adjlist **set_path, t_adjlist *next_path);
t_adjlistnode	*check_visit(t_graph *graph, t_adjlist *list_tmp);
void			collect_found_path(t_adjlist **path_tmp, t_lists *lists);
int				len_adj_list(t_adjlist *paths);
void			put_way_in_array(t_graph *graph, t_lists *lists);
void			delete_adjlistnode(t_adjlistnode *list);
void			delete_adjlist(t_adjlist *list);
void			add_link_to_path(t_graph *graph, t_adjlist *next_path, \
					t_adjlistnode *unvisited_links, t_lists *lists);
t_adjlist		*create_adj_path_node(t_adjlist *path_tmp);
void			add_link_to_path_cont(t_adjlist *path_tmp, t_adjlistnode *node);
void			reverse(t_adjlist **path);
t_adjlist		*next_step_first_node(t_graph **graph, t_adjlist *list_tmp, \
										t_adjlist **path, t_lists *lists);
int				init_step_next(t_adjlist *list_tmp, int len);
t_adjlist		*next_step_next_node(t_graph *graph, t_adjlist *list_tmp, \
										t_adjlist **path, t_lists *lists);
void			path_next_step(t_graph **graph, t_adjlist **path, \
													t_lists *lists);
t_adjlist		*copy_path(t_adjlist *path, int len);
t_adjlistnode	*find_end(t_adjlist *path);
void			print_room_list(t_input *input);
void			print_link_list(t_input *input);
void			print_array(int *array, int len);
void			print_path(t_adjlist *path);
void			print_path_continue(t_adjlistnode *tmp_width, int *len);
void			print_graph(t_graph *graph);
void			print_result(int *res, int lent, int *array);
void			print_ants(t_lists **lists);
void			print_ants_cont(t_lists **lists, t_ant *tmp, \
										t_adjlistnode *path_tmp);

#endif
