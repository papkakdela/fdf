# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grinko <grinko@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 18:34:06 by grinko            #+#    #+#              #
#    Updated: 2020/02/02 14:40:40 by grinko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror
SRCS = srcs/main.c srcs/node.c srcs/functions.c srcs/onemore.c srcs/readfile.c srcs/window.c
INC = srcs/fdf.h
OBJS = srcs/main.o srcs/node.o srcs/functions.o srcs/onemore.o srcs/readfile.o srcs/window.o
LIB = libft/
LIBA = libft/libft.a
GNL = gnl/get_next_line.c

all: $(NAME)

$(OBJS): %.o: %.c
	gcc -c -g $(FLAGS) $< -o $@

$(LIBA):
	make -C $(LIB)

$(NAME): $(LIBA) $(OBJS)
	gcc $(SRCS) $(GNL) $(LIBA) -lmlx -framework OpenGl -framework AppKit $(FLAGS) -o $(NAME)
clean:
	/bin/rm -f $(OBJS)
	make -C $(LIB) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIB) fclean

re: fclean all
.PHONY : all clean fclean re