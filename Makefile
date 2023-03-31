# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 17:08:22 by hece              #+#    #+#              #
#    Updated: 2023/03/31 17:08:22 by hece             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_B = so_long_b
CC = @gcc
RM = @rm -f
FLAGS = -Wall -Wextra -Werror -g3

YELLOW = \033[33;49;1m
CYAN = \033[33;36;1m
END = \033[0;0m

LIBFT_DIR = ./lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./lib/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

MLX_DIR = ./lib/mlx
MLX = $(MLX_DIR)/libmlx.a
MLX_ARG = -framework OpenGl -framework AppKit

SRC = $(wildcard src/*.c)
B_SRC = $(wildcard bonus/*.c)

OBJ = ${SRC:.c=.o}
B_OBJ = ${B_SRC:.c=.o}

all: $(NAME)

$(NAME):	$(OBJ) $(LIBFT) $(PRINTF) $(MLX)
			$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLX) $(MLX_ARG) -o $(NAME) 
			@echo "$(YELLOW)${NAME} ✔️"
			@echo "$(CYAN)Mandatory files compiled successfully ✔️$(END)"

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(PRINTF):
	@make -s -C $(PRINTF_DIR)

$(MLX):
	@make -s -C $(MLX_DIR)

bonus: $(NAME_B)

$(NAME_B): 	$(B_OBJ) $(LIBFT) $(PRINTF) $(MLX)
			$(CC) $(FLAGS) $(B_OBJ) $(LIBFT) $(PRINTF) $(MLX) $(MLX_ARG) -o $(NAME_B) 
			@echo "$(YELLOW)${NAME_B} ✔️$(END)"
			@echo "$(CYAN)Bonus files compiled successfully ✔️$(END)"
n:
	norminette src bonus inc

clean:
	${RM} ${OBJ}
	${RM} ${B_OBJ}
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(PRINTF_DIR) clean

fclean: clean
	${RM} ${NAME}
	${RM} ${NAME_B}
	@make -s -C $(LIBFT_DIR) fclean
	@make -s -C $(PRINTF_DIR) fclean

re: clean all

.PHONY: all clean fclean re bonus