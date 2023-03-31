# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 17:07:41 by hece              #+#    #+#              #
#    Updated: 2023/03/31 17:07:42 by hece             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = @gcc
RM = @rm -f
AR = ar rcs
FLAGS = -Wall -Wextra -Werror

YELLOW = \033[33;49;1m
END = \033[0;0m

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	$(AR) $(NAME) *.o
	@echo "$(YELLOW)${NAME} ✔️$(END)"

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus