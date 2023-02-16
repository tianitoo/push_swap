# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hnait <hnait@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 16:24:47 by hnait             #+#    #+#              #
#    Updated: 2023/02/13 15:53:02 by hnait            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ps.a
CC = cc
FLAGS = 
AR = ar -r
RM = rm -f
HEAD = push_swap.h
MK = make
LIBFT = ./libft/libft.a
HEADLIBFT = ./libft/libft.h
PRINTF = ./ft_printf/libftprintf.a
HEADPRINTF = ./ft_printf/ft_printf.h
PUSH_SWAP = push_swap

SRC = instructions.c\
		push_swap.c\
		stack.c\
		sort.c

OBJ = $(SRC:.c=.o)

all: $(NAME)
		$(MK) -C ./libft
		$(MK) -C ./ft_printf
		$(CC) main.c $(NAME) $(LIBFT) $(PRINTF) -o $(PUSH_SWAP) 

	
$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

%.o : %.c $(HEAD)
		$(CC) -c $< -o $@ $(FLAGS)

clean:
		$(RM) $(OBJ) $(BNSOBJ)
		$(MK) clean -C libft
		$(MK) clean -C ft_printf
		

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	$(RM) $(PRINTF)
	$(RM) $(PUSH_SWAP)
	

re: fclean all

.PHONY: all bonus clean fclean re