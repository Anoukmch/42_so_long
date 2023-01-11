# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 15:11:48 by amechain          #+#    #+#              #
#    Updated: 2023/01/11 15:42:22 by amechain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -I include -lglfw -L "/Users/amechain/source/projects/rank02/so_long/homebrew/Cellar/glfw/3.3.8/lib/"

NAME = 	so_long

SRC = 	so_long.c \
		check_extension.c \
		check_path.c \
		create_figures.c \
		create_map.c \
		initialize.c \
		start_game.c \
		utils.c \
		win.c \
		x_key.c

SRCS = $(addprefix ./sources/, $(SRC))

OBJS = $(SRCS:.c=.o)

LIBS_DIR = ./includes/libs

MLX_DIR = ./mlx42

LIBS_NAME = libs.a

MLX_NAME = libmlx42.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_DIR)/$(LIBS_NAME) $(MLX_DIR)/$(MLX_NAME)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $^ -o $@

$(LIBS_DIR)/$(LIBS_NAME):
	make -sC $(LIBS_DIR)

$(MLX_DIR)/$(MLX_NAME):
	make -sC $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBS_DIR)
	@rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBS_DIR)
	@rm -f $(NAME)

re: fclean all

norm:
	-norminette ./includes $(SRCS) $(NAME).h

.PHONY: all clean fclean re norm
