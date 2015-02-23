##
## Makefile for makefile in /home/verove_j/Document/Abstract/srcs
## 
## Made by Jordan Verove
## Login   <verove_j@epitech.net>
## 
## Started on  Mon Feb 16 09:19:31 2015 Jordan Verove
## Last update Mon Feb 23 16:06:29 2015 Roman Grout
##

CC =		g++

RM =		rm -f

INCLUDES =	-Iinc/

CXXFLAGS =	-Werror -Wextra -Wall

SRC =		srcs/Error.cpp \
		srcs/Instructions.cpp \
		srcs/IOperand.cpp \
		srcs/main.cpp \
		srcs/Operand.cpp

OBJ =		$(SRC:.cpp=.o)

NAME =		avm

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

%.o:		%.cpp
		$(CC) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
