# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsteyn <gsteyn@student.wethinkcode.co.z    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 09:25:10 by gsteyn            #+#    #+#              #
#    Updated: 2018/07/24 17:34:52 by gsteyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = lem-in
SRC      = main.c parse_input.c get_input.c init_ants.c init_rooms.c \
		   check_input.c get_links.c find_path.c dijkstra.c get_heuristic.c
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