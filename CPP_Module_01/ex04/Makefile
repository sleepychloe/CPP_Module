# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 10:39:42 by yhwang            #+#    #+#              #
#    Updated: 2023/02/07 14:47:36 by yhwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS_DIR = ./srcs/
TEST_DIR = ./test_files/

FILES = $(SRCS_DIR)main \
		$(SRCS_DIR)replace_line

INCS_DIR = ./incs

SRCS = $(addsuffix .cpp, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

%.o: %.cpp $(INCS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -I$(INCS_DIR)

clean:
	$(RM) $(OBJS) $(TEST_DIR)*.replace

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
