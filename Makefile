# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/23 16:36:58 by amyburgh          #+#    #+#              #
#    Updated: 2018/05/24 00:38:04 by amyburgh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
CFLAGS = -Wall -Werror -Wextra

OBJS_DIR = objs
SRCS_DIR = srcs
INCS_DIR = -I includes

SRCS_FILES = main.c	input.c	validate.c	solver.c	map.c \
	   utilities.c	utilities2.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS_FILES:.c=.o))

.PHONY:	all clean fclean re

all: $(shell mkdir -p objs) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "executable: \033[32m[CREATED]\033[0m"

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCS_DIR) -o $@ -c $^

clean:
	@rm -rf $(OBJS_DIR)
	@echo "object_files: \033[32m[REMOVED]\033[0m"

fclean:	clean
	@rm -f $(NAME)
	@echo "executable: \033[32m[REMOVED]\033[0m"

re:	fclean all
