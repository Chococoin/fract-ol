# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 08:52:14 by glugo-mu          #+#    #+#              #
#    Updated: 2025/05/08 11:31:59 by glugo-mu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)

NAME = fractol

BONUS_NAME = fractol_bonus

SRCS = fractol.c utils.c utils_2.c colours.c draw.c fractals.c hooks.c hooks_utils.c
BONUS_SRCS = bonus/burning.c src/draw.c src/utils.c src/utils_2.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

ifeq ($(UNAME), Darwin)
	MLX_DIR = ./mlx
	MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -Wl,-rpath,$(MLX_DIR)
else
	MLX_DIR = ./mlx_linux
	MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

bonus: $(BONUS_NAME)
	$(BONUS_NAME): $(BONUS_OBJS)
		$(CC) $(CFLAGS) $(BONUS_OBJS) $(MLX_FLAGS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_OBJS)

re: fclean all

.PHONY: all clean fclean re
