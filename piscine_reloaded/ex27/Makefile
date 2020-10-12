# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 10:07:57 by tbrizon           #+#    #+#              #
#    Updated: 2019/04/02 10:08:04 by tbrizon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
CC = gcc
FLAGS =	-c -Wall -Werror -Wextra
FILES.C =	./srcs/*.c

all :
		$(CC) $(FLAGS) $(FILES.C)
		$(CC) -o $(NAME) *.o

clean :
		rm -f *.o

fclean :
		rm -f $(NAME)
re : fclean
	MAKE