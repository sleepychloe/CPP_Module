# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 19:38:14 by yhwang            #+#    #+#              #
#    Updated: 2022/12/24 23:04:45 by yhwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account
CC = c++
CFALGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f

FILES = test \
		Account

SRCS_DIR = ./

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .cpp, $(FILES)))
OBJS = $(addprefix $(SRCS_DIR), $(addsuffix .o, $(FILES)))

.cpp.o: $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
