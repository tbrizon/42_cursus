# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrizon <tbrizon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/15 17:09:42 by tbrizon           #+#    #+#              #
#    Updated: 2019/11/11 14:39:30 by jjaegle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC_PATH = ./srcs/

SC = fn_is.c \
	fn_thread.c \
	g_c.c \
	hash.c \
	list.c \
	main.c \
	parsing.c \
	path.c \
	print.c \
	soluce.c \
	solve.c \
	thread2.c \
	tools.c \
	tube.c \
	utility.c

LIBFT = ./libft

LIBFT_A = ./libft/libftprintf.a

D_SRCS = ./srcs

D_OBJ = ./temporary

HEADER = ./includes

CC = gcc $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix $(D_SRCS)/,$(SC))

OBJ = $(addprefix $(D_OBJ)/,$(SC:.c=.o))

make foo=bar target

all: $(NAME)

$(NAME): $(LIBFT_A) $(SRCS) ./includes/lem_in.h
	@$(CC) $(FLAGS) -o $(NAME) -I $(HEADER) $(SRCS) $(LIBFT_A)
	@echo "\033[32m[OK]  $(NAME) created\n\033[0m"

$(LIBFT_A):
	@echo "\033[34mCreation of $(NAME) ...\n\033[0m"
	@make -C $(LIBFT)

clean:
	@make clean -C ./libft/

fclean-lib:
	@make fclean -C ./libft/
	@echo "\033[33mRemoval of $(NAME)...\033[0m"
	@rm -f $(NAME)
	@echo "\033[31m$(NAME) deleted\n\033[0m"

fclean:
	@echo "\033[33mRemoval of $(NAME)...\033[0m"
	@rm -f $(NAME)
	@echo "\033[31m$(NAME) deleted\n\033[0m"
	@rm -rf .venv

re: fclean all

re-lib: fclean-lib all

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(D_SRCS)/

install:
	@echo "environement created and activated"
	@echo "upgrading pip3.."
	@pip3 install --upgrade pip
	@echo "installing matplotlib and networkX.."
	@pip3 install networkX
	@echo "networkX installed"
	@pip3 install matplotlib
	@echo "matplotlib installed"

.PHONY: all, clean, fclean, re
