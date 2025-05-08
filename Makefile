# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 08:52:14 by glugo-mu          #+#    #+#              #
#    Updated: 2025/05/08 14:20:22 by glugo-mu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)

NAME = fractol

BONUS_NAME = fractol_bonus

SRCS =	src/fractol.c src/utils.c src/utils_2.c src/colours.c src/draw.c src/fractals.c \
		src/hooks.c src/hooks_utils.c 
BONUS_SRCS =	bonus/burning.c bonus/hooks.c bonus/fractol.c bonus/draw.c bonus/utils.c \
				src/utils_2.c src/colours.c src/fractals.c src/hooks_utils.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

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

bonus: $(BONUS_NAME)
$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(MLX_FLAGS) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_OBJS)

re: fclean all

.PHONY: all clean fclean re bonus
