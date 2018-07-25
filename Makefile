# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 09:25:10 by gsteyn            #+#    #+#              #
#    Updated: 2018/07/25 12:47:33 by gsteyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = lem-in
SRC      = main.c parse_input.c get_input.c init_ants.c init_rooms.c \
		   check_input.c get_links.c find_path.c brute_end_dist.c \
		   get_heuristic.c move_ant.c rooms_connect_to_end.c
SDIR 	 = srcs
ODIR 	 = bin
SRCS 	 = $(patsubst %.c, srcs/%.c, $(SRC))
OBJS 	 = $(patsubst %.c, bin/%.o, $(SRC)) bin/get_next_line.o
FLAGS 	 = -Wall -Wextra -Werror
INCLUDES = -I libft -I gnl -I includes
LIBS 	 = libft/libft.a
GNL 	 = gnl/get_next_line.c

all: $(NAME)

$(NAME): gnl $(OBJS) libs $(ODIR)
	gcc -o $(NAME) $(FLAGS) $(INCLUDES) $(OBJS) -L. $(LIBS)

$(ODIR):
	mkdir -p $(ODIR)

$(ODIR)/%.o: $(SDIR)/%.c
	gcc -c $(INCLUDES) $(FLAGS) -o $@ $<

li: $(OBJS)

#libs:
#	make -C ./libft fclean && make -C ./libft

libs:
	make -C ./libft

gnl:
	gcc -c $(FLAGS) $(INCLUDES) -o ./bin/get_next_line.o $(GNL)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all