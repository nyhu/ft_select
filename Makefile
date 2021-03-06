# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tboos <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/07 15:35:19 by tboos             #+#    #+#              #
#    Updated: 2016/05/23 08:27:49 by tboos            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: fclean re
.SUFFIXES:
NAME = ft_select
FLAGS = -Wall -Wextra -Werror -std=gnu99
SRC = main.c add_del.c arrow_select.c free_select.c keyparsing.c \
	termwin.c signal_select.c bonus_select.c termcaps_select.c
SRCS = $(foreach S, $(SRC), srcs/$(S))
OBJ = $(SRCS:.c=.o)
TERMCAPS = -lm -lncurses
HEAD = -I libft/includes -I includes
OS = $(shell uname -s)

ifeq ($(OS), Linux)
	FLAGS += -D LINUX
endif

all: lib $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(HEAD) $^ -L libft -l ft -o $@ $(TERMCAPS)

%.o: %.c libft/libft.a
	gcc $(FLAGS) $(HEAD)  -c $< -o $@

lib:
	make -C libft

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

re: fclean lib $(DNAME)
