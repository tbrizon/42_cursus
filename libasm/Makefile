#____________CONFIG____________#

NAME = libasm.a
PATH_SRC = ./src/

AS = nasm
ASFLAGS = -f macho64
CC = cc -Wall -Wextra -Werror

#____________FILES____________#

SRC =	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s	\
		ft_read.s	\
		ft_strdup.s

OBJ = $(addprefix $(PATH_SRC), $(SRC:.s=.o))

HEADER = ./includes

#____________REGLES____________#

.PHONY: clean fclean re test clean_test

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

