# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proton <proton@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 14:44:13 by proton            #+#    #+#              #
#    Updated: 2025/04/13 12:14:28 by proton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.POSIX:
.SUFFIXES:

NAME		=	Bureaucrat
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
SRC			=	main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp \
				RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp

INCLUDES	=	Aform.hpp Bureaucrat.hpp Intern.hpp ShrubberyCreationForm.hpp \
				PresidentialPardonForm.hpp RobotomyRequestForm.hpp

OBJS		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: all

.PHONY: clean flcean