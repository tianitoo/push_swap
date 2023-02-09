# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hnait <hnait@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 16:24:47 by hnait             #+#    #+#              #
#    Updated: 2023/02/06 12:31:52 by hnait            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
FLAGS = -Wall -Werror -Wextra
AR = ar -r
RM = rm -f
HEAD = libft.h
 
SRC = ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isprint.c\
		ft_isdigit.c\
		ft_isascii.c\
		ft_itoa.c\
		ft_memchr.c\
		ft_memcpy.c\
		ft_memset.c\
		ft_memcmp.c\
		ft_memmove.c\
		ft_split.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strchr.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_strdup.c\
		ft_strncmp.c\
		ft_strlcat.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c

BNSSRC = ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c

OBJ = $(SRC:.c=.o)
BNSOBJ = $(BNSSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

%.o : %.c $(HEAD)
		$(CC) -c $< -o $@ $(FLAGS)

bonus: $(BNSOBJ)
		$(AR) $(NAME) $(BNSOBJ)

clean:
		$(RM) $(OBJ) $(BNSOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re