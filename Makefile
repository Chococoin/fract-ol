# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 08:52:14 by glugo-mu          #+#    #+#              #
#    Updated: 2025/04/30 14:23:48 by glugo-mu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)

NAME = fractol

SRCS = fractol.c utils.c utils2.c colours.c draw.c fractals.c hooks.c hooks_utils.c

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

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
