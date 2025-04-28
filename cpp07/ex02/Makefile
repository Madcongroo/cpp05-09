
.POSIX:
.SUFFIXES:

NAME		=	array
CC		=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
SRC		=	main.cpp
INCLUDES	=	Array.hpp

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
