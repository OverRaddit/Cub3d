# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 21:25:08 by jinyoo            #+#    #+#              #
#    Updated: 2022/07/14 20:39:05 by jinyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

NAME = cub3d

SRCS_DIR = src
SRCS =	src/main.c \
		src/error/error.c \
		src/parsing/parse_color.c \
		src/parsing/parse_map.c \
		src/parsing/parse.c \
		src/parsing/validation.c \
		src/utils/util.c
OBJS = $(SRCS:.c=.o)

MLX_NAME = mlx
MLX_DIR = include/minilibx_opengl_20191021

GNL_NAME = gnl
GNL_DIR = include/get_next_line

LIBFT_NAME = ft
LIBFT_DIR = include/libft

.PHONY : all clean fclean re

$(NAME) : $(OBJS)
	$(MAKE) -C $(MLX_DIR) all
	$(MAKE) -C $(GNL_DIR) all
	$(MAKE) -C $(LIBFT_DIR) all
	$(CC) $(CFLAGS) -L$(MLX_DIR) -l$(MLX_NAME) \
			-L$(GNL_DIR) -l$(GNL_NAME) \
			-L$(LIBFT_DIR) -l$(LIBFT_NAME) \
			-framework OpenGL -framework AppKit $^ -o $@

$(SRCS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(GNL_DIR) -I$(LIBFT_DIR) -c $< -o $@

all : $(NAME)

clean :
	@rm -rf $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean :
	@rm -rf $(NAME) $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(GNL_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re :
	$(MAKE) fclean
	$(MAKE) all
