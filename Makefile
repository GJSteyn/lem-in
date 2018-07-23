# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 09:25:10 by gsteyn            #+#    #+#              #
#    Updated: 2018/07/23 15:26:22 by gsteyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = lem-in
SRC      = main.c parse_input.c get_map.c init_ants.c init_rooms.c
SDIR 	 = srcs
ODIR 	 = bin
SRCS 	 = $(patsubst %.c, srcs/%.c, $(FILES))
OBJS 	 = $(patsubst %.c, bin/%.o, $(FILES)) ./bin/get_next_line.o
FLAGS 	 = -Wall -Wextra -Werror
INCLUDES = -I libft -I gnl -I includes
LIBS 	 = libft/libft.a
GNL 	 = gnl/get_next_line.c

all: $(NAME)

$(NAME1): $(OBJS) libs gnl
	gcc -o $(NAME1) $(FLAGS) $(INCLUDES) $(OBJS) srcs/push_swap.c -L. $(LIBS)

libs:
	make -C ./libft fclean && make -C ./libft

gnl:
	gcc -c $(FLAGS) $(INCLUDES) -o ./bin/get_next_line.o $(GNL)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME1) $(NAME2)

re: fclean all