# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 23:18:22 by upolat            #+#    #+#              #
#    Updated: 2024/06/12 01:23:51 by upolat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = src/mandatory

SOURCES =		$(SRC_DIR)/main.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

libft_dir := library/libft
libft := $(libft_dir)/libft.a

INCLUDES = -I./include -I$(libft_dir)

all: $(NAME)

$(NAME): $(OBJECTS) $(libft)
	cc $(CFLAGS) $(INCLUDES) $(OBJECTS) -L$(libft_dir) -lft -o $@

$(libft):
	$(MAKE) -C $(libft_dir)

%.o: %.c
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	make -C $(libft_dir) clean

fclean: clean
	rm -f $(NAME)
	make -C $(libft_dir) fclean

re: fclean all

.PHONY: all clean fclean re
