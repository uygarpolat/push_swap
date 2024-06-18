# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 02:19:54 by upolat            #+#    #+#              #
#    Updated: 2024/06/18 03:23:34 by upolat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

SRC_DIR = src/mandatory
SRC_BONUS_DIR = src/bonus

SOURCES =		$(SRC_DIR)/push_swap.c $(SRC_DIR)/handle_error.c \
				$(SRC_DIR)/moves_1.c $(SRC_DIR)/moves_2.c $(SRC_DIR)/moves_3.c \
				$(SRC_DIR)/execute_1.c $(SRC_DIR)/execute_2.c \
				$(SRC_DIR)/sorters.c $(SRC_DIR)/find_min_max.c \
				$(SRC_DIR)/utils.c
SOURCES_BONUS =	$(SRC_BONUS_DIR)/push_swap_bonus.c $(SRC_BONUS_DIR)/handle_error_bonus.c \
				$(SRC_BONUS_DIR)/moves_1_bonus.c $(SRC_BONUS_DIR)/moves_2_bonus.c $(SRC_BONUS_DIR)/moves_3_bonus.c \
				$(SRC_BONUS_DIR)/execute_1_bonus.c $(SRC_BONUS_DIR)/execute_2_bonus.c \
				$(SRC_BONUS_DIR)/sorters_bonus.c $(SRC_BONUS_DIR)/find_min_max_bonus.c \
				$(SRC_BONUS_DIR)/utils_bonus.c

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

libft_dir := library/libft
libft := $(libft_dir)/libft.a

INCLUDES = -I./include -I$(libft_dir)

all: $(NAME)

$(NAME): $(OBJECTS) $(libft)
	cc $(CFLAGS) $(INCLUDES) $(OBJECTS) -L$(libft_dir) -lft -o $@

$(libft):
	$(MAKE) -C $(libft_dir)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJECTS_BONUS) $(libft)
	cc $(CFLAGS) $(INCLUDES) $(OBJECTS_BONUS) -L$(libft_dir) -lft -o $@

%.o: %.c
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS) .bonus
	make -C $(libft_dir) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C $(libft_dir) fclean

re: fclean all

.PHONY: all clean fclean re bonus

