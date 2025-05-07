# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proton <proton@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 16:38:01 by proton            #+#    #+#              #
#    Updated: 2025/05/06 16:38:33 by proton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.POSIX:
.SUFFIXES:

NAME		=	Mutant
CC		=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
SRC		=	main.cpp
INCLUDES	=	MutantStack.hpp

OBJS		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -o $@ -c $< 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: all

.PHONY: all re
