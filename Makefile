# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/08 11:34:02 by vsmolii           #+#    #+#              #
#    Updated: 2019/07/18 20:46:17 by vsmolii          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = -I ./includes
SRCS =	./srcs/main.c \
		./srcs/input/parsing.c \
		./srcs/input/get_ant.c \
		./srcs/input/get_room_1.c \
		./srcs/input/get_room_2.c \
		./srcs/input/get_link_1.c \
		./srcs/input/get_link_2.c \
		./srcs/adjacency_list/graph_1.c \
		./srcs/adjacency_list/graph_2.c \
		./srcs/adjacency_list/get_edges.c \
		./srcs/adjacency_list/path_1.c \
		./srcs/adjacency_list/path_2.c \
		./srcs/adjacency_list/path_3.c \
		./srcs/adjacency_list/path_4.c \
		./srcs/adjacency_list/ant_1.c \
		./srcs/adjacency_list/ant_2.c \
		./srcs/adjacency_list/analyser.c \
		./srcs/adjacency_list/delete_ant.c \
		./srcs/print/print_1.c \
		./srcs/print/print_2.c \

LIBFT = -L./libft/ -lft_printf

LIB_LEM_IN = lem_in.a

DEBUG =  -fsanitize=address

OBJ = ./obj

EXE = lem-in

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;36m
RED_EXTRA = \033[1;31m
GREEN_EXTRA = \033[1;32m
BLUE_EXTRA = \033[1;36m

all: $(EXE)
$(EXE):
	@gcc -Wall -Wextra -Werror $(SRCS) $(LIBFT) $(INCLUDES) -o $(EXE)

clean:
	@if [ ! -d " ./obj" ]; then \
	/bin/rm -rf $(OBJ); \
	fi
	#/bin/rm -rf $(OBJ)
	# make -C libft clean

fclean: clean
	@if [ ! -a "$(LIB_LEM_IN)" ]; then \
	/bin/rm -f $(LIB_LEM_IN); \
	fi

	@if [ -a "$(EXE)" ]; then \
	echo "Deleting execetable $(RED_EXTRA)$(EXE)$(RESET)"; \
	/bin/rm -f $(EXE); \
	fi
	#bin/rm -f $(LIB_FILLER)
	#bin/rm -f $(EXE)
	# make -C libft fclean
	@echo "$(BlUE_EXTRA)fclean$(BLUE); Complete$(RESET)"

re: fclean all
