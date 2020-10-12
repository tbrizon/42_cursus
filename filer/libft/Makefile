# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrizon <tbrizon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 16:32:09 by tbrizon           #+#    #+#              #
#    Updated: 2019/09/10 10:45:07 by tbrizon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -c -Wall -Werror -Wextra
FILES = ./get_next_line.c \
		./ft_atoi.c \
		./ft_bzero.c \
		./ft_get_next_line.c \
		./ft_intlen.c \
		./ft_isalnum.c \
		./ft_isalpha.c \
		./ft_isascii.c \
		./ft_isblank.c \
		./ft_isdigit.c \
		./ft_isprint.c \
		./ft_itoa.c \
		./ft_lstadd.c \
		./ft_lstdel.c \
		./ft_lstdelfirst.c \
		./ft_lstdelone.c \
		./ft_lstiter.c \
		./ft_lstmap.c \
		./ft_lstnew.c \
		./ft_lstremoveone.c \
		./ft_makestr.c \
		./ft_memalloc.c \
		./ft_memccpy.c \
		./ft_memchr.c \
		./ft_memcmp.c \
		./ft_memcpy.c \
		./ft_memdel.c \
		./ft_memmove.c \
		./ft_memset.c \
		./ft_putchar.c \
		./ft_putchar_fd.c \
		./ft_putendl.c \
		./ft_putendl_fd.c \
		./ft_putnbr.c \
		./ft_putnbr_fd.c \
		./ft_putstr.c \
		./ft_putstr_fd.c \
		./ft_putnstr.c \
		./ft_strcat.c \
		./ft_strchr.c \
		./ft_strclr.c \
		./ft_strcmp.c \
		./ft_strcpy.c \
		./ft_strdel.c \
		./ft_strdup.c \
		./ft_strequ.c \
		./ft_striter.c \
		./ft_striteri.c \
		./ft_strjoin.c \
		./ft_strlcat.c \
		./ft_strlen.c \
		./ft_strmap.c \
		./ft_strmapi.c \
		./ft_strncat.c \
		./ft_strncmp.c \
		./ft_strncpy.c \
		./ft_strndup.c \
		./ft_strnequ.c \
		./ft_strnew.c \
		./ft_strnstr.c \
		./ft_strrchr.c \
		./ft_strsplit.c \
		./ft_strstr.c \
		./ft_strsub.c \
		./ft_strtrim.c \
		./ft_tolower.c \
		./ft_toupper.c \
		./ft_strrev.c \
		./ft_strjoinfree.c \
		./ft_sort_integrer_tab.c \
		./ft_power.c \
		./ft_len_base.c \
		./ft_putnbr_base.c \
		./ft_lstpush.c \
		./ft_lstdelfirst.c \
		./my_free.c \
		./ft_lstrev.c \

OBJ = $(FILES:.c=.o)

HEADER = ./libft.h

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "\033[34mCreation of libft.a ...\033[0m"
	@ar rc $(NAME) $(OBJ) $(HEADER)
	@ranlib $(NAME)
	@echo "\033[32m[OK]\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c -I $(HEADER) $< -o $@

clean :
	@echo "\033[34mRemove .o files ...\033[0m"
	@rm -rf $(OBJ)
	@echo "\033[31m .o deleted\033[0m"

fclean : clean
	@echo "\033[34m del libft.a ...\033[0m"
	@rm -rf $(NAME)
	@echo "\033[31m libft.a deleted\033[0m"

re : fclean
	MAKE
