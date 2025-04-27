# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proton <proton@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 01:21:00 by proton            #+#    #+#              #
#    Updated: 2025/04/26 01:21:04 by proton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.POSIX:
.SUFFIXES:

NAME		=	base
CC		=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
SRC		=	Base.cpp main.cpp
INCLUDES	=	Base.hpp A.hpp B.hpp C.hpp

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
