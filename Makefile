# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 16:24:37 by aschoenh          #+#    #+#              #
#    Updated: 2019/02/13 13:33:05 by mporzier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_ls
CC = gcc -Wall -Wextra -Werror
CC_FLAGS = -I$(LFT_PATH)/include

LFT_PATH = ./libft/
SRC_PATH = ./src/
INC_PATH = ./include/ $(LFT_PATH)
OBJ_PATH = ./obj/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_NAME = 	main.c parsing.c create_list.c utils.c display.c sort.c display_files.c display_files_l.c sort2.c ft_list_merge.c change_color.c set_color_arrays.c sort3.c acl.c init_tab.c assign_table.c

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LFT_PATH)
	$(CC) -o $(NAME) $(OBJ) -L$(LFT_PATH) -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	make -C $(LFT_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re
