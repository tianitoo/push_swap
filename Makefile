# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hnait <hnait@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 16:24:47 by hnait             #+#    #+#              #
#    Updated: 2023/03/14 10:59:32 by hnait            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc -Wall -Wextra -Werror
FLAGS = 
AR = ar -r
RM = rm -rf
HEAD = push_swap.h
MK = make
LIBFT = ./libft/libft.a
HEADLIBFT = ./libft/libft.h
PRINTF = ./ft_printf/libftprintf.a
HEADPRINTF = ./ft_printf/ft_printf.h


SRC = instructions.c\
		push_swap.c\
		stack.c\
		sort.c\
		rotations.c\
		duplicate_rotations.c\
		stack_state.c\
		get_index.c\
		get_value.c\
		get_element.c\
		best_number_of_instructions.c\
		get_from_table.c\
		longest_increasing_subseaquence.c\
		check_args.c

OBJ = $(SRC:.c=.o)

all: libft printf $(NAME)

printf:
	$(MK) -C ./ft_printf
	
libft:
	$(MK) -C ./libft

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) main.c
	$(CC) $^ -o $@

%.o : %.c $(HEAD)
	$(CC) -c $^ $(FLAGS)

clean:
		$(RM) $(OBJ) $(BNSOBJ) main.o
		$(MK) clean -C libft
		$(MK) clean -C ft_printf
		

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	$(RM) $(PRINTF)
	

re: fclean all

.PHONY: all bonus clean fclean libft printf re