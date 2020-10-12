# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/15 17:09:42 by tbrizon           #+#    #+#              #
#    Updated: 2019/05/30 14:19:10 by jjaegle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SC = 	./ft_solve.c \
		./ft_parsing.c \
		./ft_tools.c \
		./norminette.c \
		./ft_tools2.c \
		./main.c \

LIBFT = ./libft/

LIBFT_A = ./libft/libft.a

D_SRCS = ./srcs

D_OBJ = ./temporary

HEADER = ./includes/fillit.h

CC = gcc $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix $(D_SRCS)/,$(SC))

OBJ = $(addprefix $(D_OBJ)/,$(SC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@echo "\033[34mCreation of $(NAME) ...\033[0m"
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT_A) -o $(NAME)
	@echo "\033[32m[OK]  $(NAME) created\033[0m"

$(D_OBJ)/%.o: $(D_SRCS)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@make clean -C ./libft/
	@echo "\033[34mRemove fillit's .o files ...\033[0m"
	@rm -f $(OBJ)
	@rm -rf $(D_OBJ)
	@echo "\033[31m.o files are deleted\n\033[0m"

fclean: clean
	@make fclean -C ./libft/
	@echo "\033[33mRemove $(NAME)...\033[0m"
	@rm -f $(NAME)
	@echo "\033[31m$(NAME) deleted\n\033[0m"

re: fclean all

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(D_SRCS)/


.PHONY: all, clean, fclean, re