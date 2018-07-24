# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 09:25:10 by gsteyn            #+#    #+#              #
#    Updated: 2018/07/24 07:16:17 by gsteyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = lem-in
SRC      = main.c parse_input.c get_input.c init_ants.c init_rooms.c \
		   check_input.c get_links.c
SDIR 	 = srcs
ODIR 	 = bin
SRCS 	 = $(patsubst %.c, srcs/%.c, $(SRC))
OBJS 	 = $(patsubst %.c, bin/%.o, $(SRC)) bin/get_next_line.o
FLAGS 	 = -Wall -Wextra -Werror
INCLUDES = -I libft -I gnl -I includes
LIBS 	 = libft/libft.a
GNL 	 = gnl/get_next_line.c

all: $(NAME)

$(NAME): gnl $(OBJS) libs
	gcc -o $(NAME) $(FLAGS) $(INCLUDES) $(OBJS) -L. $(LIBS)

$(ODIR)/%.o: $(SDIR)/%.c
	gcc -c $(INCLUDES) $(FLAGS) -o $@ $<

libs:
	make -C ./libft fclean && make -C ./libft

gnl:
	gcc -c $(FLAGS) $(INCLUDES) -o ./bin/get_next_line.o $(GNL)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME1) $(NAME2)

re: fclean all