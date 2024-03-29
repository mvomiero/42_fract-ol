# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 15:13:55 by mvomiero          #+#    #+#              #
#    Updated: 2023/03/02 18:03:51 by mvomiero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Program name
NAME	= fractol

# Compiler
CC		= gcc
CFLAGS	= -Werror -Wextra -Wall

# Minilibx
MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Includes
INC			=	-I ./includes/\
				-I ./libft/\
				-I ./minilibx-linux/
HEADERS		=	./includes/

# Sources
SRC_PATH	=	src/

SRC			=	exit.c \
				fractol.c \
				initialization.c \
				msg.c \
				parsing_args.c \
				utils.c \
				fract_mandelbrot.c \
				render.c \
				key_events.c \
				color.c \
				color_utils.c \
				fract_julia.c \
				mouse_events_zoom.c

SRCS		= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(OBJ_PATH) $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling fractol..."
	@-$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(INC) -lXext -lX11 -lm
	@echo "\n\t\033[35;1;3mFractol ready\033[0m\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
#	@echo "Compiling object files"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	@echo "Generating obj folder"
	@mkdir $(OBJ_PATH)

$(MLX):
	@echo "Making MiniLibX..."
	@make -sC $(MLX_PATH)

$(LIBFT):
	@echo "Making libft..."
	@make -sC $(LIBFT_PATH)

bonus: all

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@echo "Removing fractol..."
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

valgrind:
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all \
	./fractol

man:
	man minilibx-linux/man/man1/mlx.1

run: all
	./fractol mandelbrot

norminette_check:
	norminette ./src
	norminette -R CheckForbiddenSourceHeader ./includes

.PHONY: all re clean fclean