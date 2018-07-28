# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 09:25:10 by gsteyn            #+#    #+#              #
#    Updated: 2018/07/28 13:35:59 by gsteyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      = lem-in
LIBNAME   = lem-in.a
SRC       = main.c parse_input.c get_input.c init_ants.c init_rooms.c \
		   check_input.c get_links.c find_path.c brute_end_dist.c \
		   get_heuristic.c move_ant.c rooms_connect_to_end.c parse_input2.c \
		   check_valid_map.c destroy_lists.c print_input.c
SDIR 	  = srcs
ODIR 	  = bin
SRCS 	  = $(patsubst %.c, srcs/%.c, $(SRC))
OBJS 	  = $(patsubst %.c, bin/%.o, $(SRC)) bin/get_next_line.o
LEMLIBOBJS= $(filter-out bin/main.o, $(OBJS))
FLAGS 	  = -Wall -Wextra -Werror
INCLUDES  = -I libft -I gnl -I includes
LIBS 	  = libft/libft.a
GNL 	  = bin/get_next_line.o

all: $(NAME)

$(NAME): $(GNL) $(OBJS) libs $(ODIR)
	gcc -o $(NAME) $(FLAGS) $(INCLUDES) $(OBJS) -L. $(LIBS)

$(ODIR)/%.o: $(SDIR)/%.c
	mkdir -p $(ODIR)
	gcc -c $(INCLUDES) $(FLAGS) -o $@ $<

$(LIBNAME): $(LEMLIBOBJS)
	ar rc $@ $^

li: $(OBJS)

libs:
	make -C ./libft

$(GNL):
	gcc -c $(FLAGS) $(INCLUDES) -o $(GNL) gnl/get_next_line.c

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(LIBNAME)

re: fclean all