# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 18:23:36 by tbrizon           #+#    #+#              #
#    Updated: 2019/04/01 18:23:38 by tbrizon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
HEADER = ./includes/
FLAGS = -Wall -Werror -Wextra

FILES.C = 	./srcs/ft_putchar.c \
			./srcs/ft_putstr.c \
			./srcs/ft_strcmp.c \
			./srcs/ft_strlen.c \
			./srcs/ft_swap.c

FILES.O = 	./ft_putchar.o \
			./ft_putstr.o \
			./ft_strcmp.o \
			./ft_strlen.o \
			./ft_swap.o

all : $(NAME)

$(NAME) :	
	$(CC) $(FLAGS) -c $(FILES.C) -I $(HEADER)
	ar rc $(NAME) $(FILES.O)
clean :
	rm -f $(FILES.O)

fclean : clean
	rm -f $(NAME) 

re : fclean
	MAKE
