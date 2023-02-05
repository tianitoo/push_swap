# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hnait <hnait@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 16:24:47 by hnait             #+#    #+#              #
#    Updated: 2023/02/01 13:15:40 by hnait            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ps.a
CC = cc
FLAGS = -Wall -Werror -Wextra
AR = ar -r
RM = rm -f
HEAD = push_swap.h

SRC = instructions.c\
		push_swap.c\
		stack.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

%.o : %.c $(HEAD)
		$(CC) -c $< -o $@ $(FLAGS)

clean:
		$(RM) $(OBJ) $(BNSOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re