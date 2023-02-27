# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 07:50:06 by yhwang            #+#    #+#              #
#    Updated: 2023/02/27 07:51:08 by yhwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = span
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS_DIR = ./srcs/

FILES = $(SRCS_DIR)main \
		$(SRCS_DIR)Span

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
