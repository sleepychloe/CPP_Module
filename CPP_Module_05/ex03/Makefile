# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 02:12:20 by yhwang            #+#    #+#              #
#    Updated: 2023/02/20 21:42:38 by yhwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS_DIR = ./srcs/

CURRENT_DIR = ./
FILE_TO_REMOVE = _shrubbery

FILES = $(SRCS_DIR)main \
		$(SRCS_DIR)Bureaucrat \
		$(SRCS_DIR)AForm \
		$(SRCS_DIR)ShrubberyCreationForm \
		$(SRCS_DIR)RobotomyRequestForm \
		$(SRCS_DIR)PresidentialPardonForm \
		$(SRCS_DIR)Intern

INCS_DIR = ./incs

SRCS = $(addsuffix .cpp, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

%.o: %.cpp $(INCS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -I$(INCS_DIR)

clean:
	$(RM) $(OBJS) $(CURRENT_DIR)*$(FILE_TO_REMOVE)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
