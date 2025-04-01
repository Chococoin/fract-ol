# Detecta el sistema operativo
UNAME := $(shell uname)

# Nombre del ejecutable
NAME = fractol

# Archivos fuente
SRCS = fractol.c utils.c colours.c draw.c fractals.c hooks.c

# Archivos objeto
OBJS = $(SRCS:.c=.o)

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Configuración específica para macOS o Linux
ifeq ($(UNAME), Darwin)
	MLX_DIR = ./mlx
	MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -Wl,-rpath,$(MLX_DIR)
else
	MLX_DIR = ./mlx_linux
	MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
endif

# Regla por defecto
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