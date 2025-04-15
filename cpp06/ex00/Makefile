# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proton <proton@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 17:40:58 by proton            #+#    #+#              #
#    Updated: 2025/04/15 11:03:16 by proton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.POSIX:
.SUFFIXES:

NAME	=	convert
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRC		=	ScalarConverter.cpp main.cpp 

OBJS	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(SRC) -o $@ -c $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: all

.PHONY: all re