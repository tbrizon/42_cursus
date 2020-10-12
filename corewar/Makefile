# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skpn <skpn@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 20:01:08 by sikpenou          #+#    #+#              #
#    Updated: 2020/04/22 18:16:55 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM_DIR=asm_folder
ASM=asm

COREWAR_DIR=vm_folder
COREWAR=corewar

LIB_DIR=lib/libft
LIB=$(LIB_DIR)/libft.a

all: $(LIB) $(ASM) $(COREWAR) Makefile

$(ASM): FORCE
	make -C $(ASM_DIR)

$(COREWAR): FORCE
	make -C $(COREWAR_DIR)

$(LIB): FORCE
	make -C $(LIB_DIR)

clean: FORCE
	make clean -C $(LIB_DIR)
	make clean -C $(ASM_DIR)
	make clean -C $(COREWAR_DIR)
	rm -f $(ASM_DIR)/auteur
	rm -f $(COREWAR_DIR)/auteur

fclean: clean FORCE
	make fclean -C $(LIB_DIR)
	make fclean -C $(ASM_DIR)
	make fclean -C $(COREWAR_DIR)

re: fclean all FORCE

FORCE:

.SILENT:
