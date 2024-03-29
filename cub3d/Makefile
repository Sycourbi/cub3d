# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 12:46:56 by sycourbi          #+#    #+#              #
#    Updated: 2024/01/31 14:18:56 by sycourbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC_DIR = src/
OBJ_DIR = obj/

SRC = $(SRC_DIR)main.c $(SRC_DIR)init.c $(SRC_DIR)error.c $(SRC_DIR)creat_copy_file.c \
	$(SRC_DIR)check_arg.c $(SRC_DIR)utils.c $(SRC_DIR)creat_map.c $(SRC_DIR)text_infile.c \
	$(SRC_DIR)color_infile.c $(SRC_DIR)verif_map.c $(SRC_DIR)text_color_check.c \
	$(SRC_DIR)creat_map_carre.c $(SRC_DIR)keypress.c $(SRC_DIR)keypress_move.c \
	$(SRC_DIR)pos_player.c $(SRC_DIR)start_mlx.c $(SRC_DIR)image.c $(SRC_DIR)raycaster.c \
	$(SRC_DIR)map_parsing.c $(SRC_DIR)wall_detector.c

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

LIB = ./libft/libft.a
MLX = ./minilibx-linux/libmlx.a

CC = gcc

CFLAG = -Wall -Wextra -Werror -g 
MFLAG = -lX11 -lXext -lm

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) -c $(CFLAG) $< -o $@ -I.

$(MLX):
	@git clone https://github.com/42Paris/minilibx-linux
	@make -C ./minilibx-linux

$(NAME): $(MLX) $(OBJ)
	@make -C ./libft
	 @$(CC) $(CFLAG) -o $(NAME) $(OBJ) $(LIB) -I. $(MLX) -I. -L/usr/local/lib $(MFLAG)

clean:
	@rm -rf minilibx-linux
	@cd libft && make clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
