# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/15 16:47:33 by vsmolii           #+#    #+#              #
#    Updated: 2019/06/07 10:30:07 by vsmolii          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_printf.a
GCCW = gcc -Wall -Werror -Wextra
SRC = ft_ad_factorial.c ft_ad_fibonacci.c ft_ad_max.c ft_ad_power2.c ft_ad_swap.c \
		ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
		ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putchar.c \
		ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c \
		ft_putstr.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
		ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
		ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
		ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnew.c ft_strnstr.c \
		ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
		ft_tolower.c ft_toupper.c ft_strnequ.c get_next_line.c \
		extra_functions_2.c extra_functions_3.c extra_functions.c ft_printf.c \
		new_work_d_2.c new_work_d.c new_work_f_format.c new_work_o.c \
		new_work_p.c new_work_s.c parsing.c \


OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		@$(GCCW) -c -g $(SRC)
		@ar rc $(NAME) $(OBJECT)
		@ranlib $(NAME)

clean:
		@/bin/rm -rf -f $(OBJECT)

fclean: clean
		@/bin/rm -rf -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
