# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 00:38:50 by yhwang            #+#    #+#              #
#    Updated: 2023/02/17 05:44:32 by yhwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = interface
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS_DIR = ./srcs/

FILES = $(SRCS_DIR)main \
		$(SRCS_DIR)AMateria \
		$(SRCS_DIR)Ice \
		$(SRCS_DIR)Cure \
		$(SRCS_DIR)Character \
		$(SRCS_DIR)MateriaSource

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
