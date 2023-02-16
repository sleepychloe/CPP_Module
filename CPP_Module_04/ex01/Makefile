# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 23:51:40 by yhwang            #+#    #+#              #
#    Updated: 2023/02/15 23:56:10 by yhwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animal
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS_DIR = ./srcs/

FILES = $(SRCS_DIR)main \
		$(SRCS_DIR)Animal \
		$(SRCS_DIR)Dog \
		$(SRCS_DIR)Cat \
		$(SRCS_DIR)WrongAnimal \
		$(SRCS_DIR)WrongCat \
		$(SRCS_DIR)Brain

INCS_DIR = ./incs

SRCS = $(addsuffix .cpp, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

%.o: %.cpp $(INCS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -I$(INCS_DIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
